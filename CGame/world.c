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
  world->floor = height - 80;
  
  init_player(20.0, world->floor, world->floor);
  add_crate(200.0, world->floor);
  add_crate(250.0, world->floor - 50);
  add_crate(250.0, world->floor - 150);
  add_crate(400.0, world->floor);
  add_crate(600.0, world->floor);
}

void draw_world(bool *pressed)
{
  al_draw_filled_rectangle(0, world->floor, world->width, world->height, al_map_rgb(255, 0, 0));
  Collision collision = detect_collision();
  
  draw_player(pressed, collision);
  draw_crates();
}

void destroy_world()
{
  destroy_crates();
  destroy_player();
  free(world);
}
