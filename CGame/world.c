//
//  world.c
//  CGame
//
//  Created by Tomasz Kasperek on 31.05.2015.
//  Copyright (c) 2015 Tomasz Kasperek. All rights reserved.
//

#include "world.h"

struct world* world = NULL;
ALLEGRO_FONT *font = NULL;
ALLEGRO_TRANSFORM camera;

void init_world(const int width, const int height)
{
  al_init_primitives_addon();
  font = al_load_ttf_font("/Library/Fonts/PTSans.ttc", 36, 0);
  
  world = malloc(sizeof(*world));
  world->width = width;
  world->height = height;
  world->map_height = world->height;
  world->map_width = 1000;
  world->ground = height - 50;
  world->image = al_load_bitmap("images/sand_center.png");
  world->grass = al_load_bitmap("images/grass.png");
  world->floor = world->ground - al_get_bitmap_height(world->grass);
  
  init_player(20.0, world->floor, world->floor);
  add_crate(200.0, world->floor);
  add_crate(250.0, world->floor - 70);
  add_crate(400.0, world->floor);
  add_crate(600.0, world->floor);
  add_crate(250.0, world->floor - 300);
  add_gem(400, 400, 200);
  add_gem(500, 300, 100);
}

float camera_update(float x, int width)
{
  float position = -(world->width / 2) + (x + (width / 2));
  if(position < 0) position = 0;
  
  if(position >= (world->map_width - (world->width))) {
    position = world->map_width - (world->width);
  }
  
  return position;
}

void draw_floor()
{
  int image_width = al_get_bitmap_width(world->image);
  int image_height = al_get_bitmap_height(world->image);
  
  int x = world->map_width / image_width;
  int y = world->height - world->ground;
  
  al_hold_bitmap_drawing(1);
  for(int i = 0; i < x + 1; i++) {
    int x_pos = i * image_width;
    for(int j = 0; j < y + 1; j++) {
      int y_pos = world->floor + (j * image_height);
      al_draw_bitmap(world->image, x_pos, y_pos, 0);
    }
  }
  al_hold_bitmap_drawing(0);
}

void draw_grass()
{
  int image_width = al_get_bitmap_width(world->grass);
  int x = world->map_width / image_width;
  
  al_hold_bitmap_drawing(1);
  for(int i = 0; i < x + 1; i++) {
    int x_pos = i * image_width;
    al_draw_bitmap(world->grass, x_pos, world->floor, 0);
  }
  al_hold_bitmap_drawing(0);
}

void draw_points()
{
  char *points;
  sprintf(points, "%d", player->points);

  float val = (float) world->width;
  float *x = &val;
  al_transform_coordinates(&camera, x, 0);
  
  al_draw_text(font, al_map_rgb(0, 0, 0), val, 10, 0, points);
}

void draw_world(int *pressed)
{
  draw_floor();
  draw_grass();
  Collisions collisions = detect_collisions(world->map_width);
  
  draw_player(pressed, collisions);
//  draw_points();
  draw_crates(crates);
  draw_gems(gems);

  float camera_position = camera_update(player->x, player->width);
  al_identity_transform(&camera);
  al_translate_transform(&camera, -camera_position, 0);
  al_use_transform(&camera);
}

void destroy_world()
{
  destroy_gems();
  destroy_crates();
  destroy_player();
  al_destroy_bitmap(world->image);
  al_destroy_bitmap(world->grass);
  al_destroy_font(font);
  free(world);
}
