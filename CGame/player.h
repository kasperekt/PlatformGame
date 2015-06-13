//
//  player.h
//  CGame
//
//  Created by Tomasz Kasperek on 31.05.2015.
//  Copyright (c) 2015 Tomasz Kasperek. All rights reserved.
//

#ifndef __CGame__player__
#define __CGame__player__

#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "collisiontype.h"

typedef enum {
  LEFT = ALLEGRO_FLIP_HORIZONTAL,
  RIGHT = 0
} PlayerDirection;

typedef enum {
  ON_FLOOR = (1 << 0),
  FALLING = (1 << 1),
  ON_PLATFORM = (1 << 2)
} PlayerPosition;

struct player {
  float x, y;
  float size;
  float speed;
  float velocity_y;
  float floor_limit;
  int height, width;
  int jumping;
  int active;
  PlayerPosition position;
  PlayerDirection direction;
  ALLEGRO_BITMAP *image;
};

extern struct player* player;

void init_player(float x, float y, float floor_limit);
void move_player(bool *pressed, Collision collision);
void destroy_player();
void draw_player(bool *pressed, Collision collision);
void jump();

#endif /* defined(__CGame__player__) */
