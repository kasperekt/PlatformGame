//
//  gem.h
//  CGame
//
//  Created by Tomasz Kasperek on 13.06.2015.
//  Copyright (c) 2015 Tomasz Kasperek. All rights reserved.
//

#ifndef __CGame__gem__
#define __CGame__gem__

#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

typedef struct gems {
  int gem_id;
  int x, y;
  int width, height;
  int points;
  ALLEGRO_BITMAP *image;
  struct gems *next;
} Gems;

extern Gems *gems;

void add_gem(int x, int y, int points);
void remove_gem(int gem_id);
void destroy_gems();
void draw_gems();

#endif /* defined(__CGame__gem__) */
