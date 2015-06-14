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
  world->map_width = 0;
  world->ground = height - 50;
  world->game_timer = 0;
  world->image = al_load_bitmap("images/sand_center.png");
  world->grass = al_load_bitmap("images/grass.png");
  world->floor = world->ground - al_get_bitmap_height(world->grass);

  load_map("/Users/tomek/University/CGame/map.txt");
}

void load_map(const char* filename)
{
  FILE *fp = fopen(filename, "r");
  
  if(!fp) {
    fprintf(stderr, "Blad przy otwieraniu pliku: %s\n", strerror(errno));
    return;
  }
  
  size_t len = 0;
  ssize_t read;
  char *line = NULL;
  
  while((read = getline(&line, &len, fp)) != -1) {
    add_element(line);
  }

  fclose(fp);
  if(line) free(line);
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

void draw_points(int finished)
{
  char points[10];
  sprintf(points, "%d", player->points);
  int x = (int) camera_update(player->x, player->width);

  int x_pos = 20 + x;
  int y_pos = 10;
  int flags = 0;
  
  if(finished) {
    x_pos = (world->width / 2) + x;
    y_pos = (world->height / 2) - 30;
    flags = ALLEGRO_ALIGN_CENTRE;
//    count_points();
  }
  
  al_draw_text(font, al_map_rgb(0, 0, 0), x_pos, y_pos, flags, points);
}

void draw_world(int *pressed)
{
  draw_floor();
  draw_grass();
  Collisions collisions = detect_collisions(world->map_width);
  
  if(!collisions.finished) world->game_timer += 1000 / 60;
  
  draw_key();
  draw_player(pressed, collisions);
  draw_points(collisions.finished);
  draw_crates(crates);
  draw_gems(gems);

  float camera_position = camera_update(player->x, player->width);
  al_identity_transform(&camera);
  al_translate_transform(&camera, -camera_position, 0);
  al_use_transform(&camera);
}

void count_points()
{
  int time_points = player->points - (world->game_timer / 100);
  if(time_points < 0) {
    time_points = 0;
  }
  
  player->points = player->points + time_points;
}

void destroy_world()
{
  destroy_key();
  destroy_gems();
  destroy_crates();
  destroy_player();
  al_destroy_bitmap(world->image);
  al_destroy_bitmap(world->grass);
  al_destroy_font(font);
  free(world);
}

void add_element(char *data)
{
  int type;
  char* str = strtok(data, "=,");
  sscanf(str, "%d", &type);
  
  switch(type) {
    case 0: {
      float player_x, player_y;
      int map_width;
      
      char *map_str = strtok(NULL, ",");
      char *x_str = strtok(NULL, ",");
      char *y_str = strtok(NULL, ",");
      
      sscanf(map_str, "%d", &map_width);
      sscanf(x_str, "%f", &player_x);
      if(*y_str == 'x') player_y = world->floor;
      else sscanf(y_str, "%f", &player_y);
      
      world->map_width = map_width;
      init_player(player_x, player_y, world->floor);
      break;
    }
    case 1: {
      float x, y;
      char *x_str = strtok(NULL, ",");
      char *y_str = strtok(NULL, ",");
      
      sscanf(x_str, "%f", &x);
      if(*y_str == 'x') y = world->floor;
      else sscanf(y_str, "%f", &y);
      
      add_crate(x, y);
      break;
    }
    case 2: {
      int x, y, points;
      char *x_str = strtok(NULL, ",");
      char *y_str = strtok(NULL, ",");
      char *points_str = strtok(NULL, ",");
      
      sscanf(x_str, "%d", &x);
      sscanf(y_str, "%d", &y);
      sscanf(points_str, "%d", &points);
      
      add_gem(x, y, points);
      break;
    }
    case 3: {
      int x, y;
      char *x_str = strtok(NULL, ",");
      char *y_str = strtok(NULL, ",");
      
      sscanf(x_str, "%d", &x);
      if(*y_str == 'x') y = world->floor;
      else sscanf(y_str, "%d", &y);
      
      add_key(x, y);
      break;
    }
    default:
      printf("None\n");
  }
}
