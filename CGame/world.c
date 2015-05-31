//
//  world.c
//  CGame
//
//  Created by Tomasz Kasperek on 31.05.2015.
//  Copyright (c) 2015 Tomasz Kasperek. All rights reserved.
//

#include "world.h"

void init_world()
{
  al_init_primitives_addon();
  init_player(20.0, 10.0);
}

void draw_world(const int width, const int height)
{
  al_draw_filled_rectangle(0, height - 100, width, height, al_map_rgb(255, 0, 0));
  draw_player();
}

void destroy_world()
{
  destroy_player();
}
