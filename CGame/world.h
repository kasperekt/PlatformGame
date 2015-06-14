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
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "player.h"
#include "crate.h"
#include "collision.h"
#include "gem.h"
#include "key.h"

struct world {
  float floor, ground;
  int width, height;
  int map_width, map_height;
  ALLEGRO_BITMAP *image;
  ALLEGRO_BITMAP *grass;
};

void init_world(const int width, const int height);
void load_map(const char *filename);
void add_element(char *data);
float camera_update(float x, int width);
void draw_floor();
void draw_grass();
void draw_points();
void draw_world(int *pressed);
void destroy_world();

#endif /* defined(__CGame__world__) */
