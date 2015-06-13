//
//  world.c
//  CGame
//
//  Created by Tomasz Kasperek on 31.05.2015.
//  Copyright (c) 2015 Tomasz Kasperek. All rights reserved.
//

#include "world.h"

struct world* world = NULL;

void init_world(const int width, const int height)
{
  al_init_primitives_addon();
  
  world = malloc(sizeof(*world));
  world->width = width;
  world->height = height;
  world->floor = height - 100;
  world->image = al_load_bitmap("images/sand_center.png");
  
  init_player(20.0, world->floor, world->floor);
  add_crate(200.0, world->floor);
  add_crate(250.0, world->floor - 50);
  add_crate(400.0, world->floor);
  add_crate(600.0, world->floor);
}

void draw_floor()
{
  int image_width = al_get_bitmap_width(world->image);
  int image_height = al_get_bitmap_height(world->image);
  
  int x = world->width / image_width;
  int y = world->height - world->floor;
  
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

void draw_world(int *pressed)
{
  draw_floor();
  Collision collision = detect_collision();
  
  draw_player(pressed, collision);
  draw_crates();
}

void destroy_world()
{
  destroy_crates();
  destroy_player();
  al_destroy_bitmap(world->image);
  free(world);
}
