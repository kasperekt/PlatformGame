//
//  world.h
//  CGame
//
//  Created by Tomasz Kasperek on 31.05.2015.
//  Copyright (c) 2015 Tomasz Kasperek. All rights reserved.
//

#ifndef __CGame__world__
#define __CGame__world__

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "player.h"
#include "crate.h"
#include "collision.h"

struct world {
  float floor;
  int width, height;
  ALLEGRO_BITMAP *image;
};

void init_world(const int width, const int height);
void draw_floor();
void draw_world(int *pressed);
void destroy_world();

#endif /* defined(__CGame__world__) */
