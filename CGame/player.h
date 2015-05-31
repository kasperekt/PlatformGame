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
#include "collision.h"

struct player {
  float x, y;
  float size;
  float speed;
  float velocity_y;
  float floor_limit;
  int on_ground;
};

extern struct player* player;

void init_player(float x, float y, float floor_limit);
void move_player(bool *pressed, CollisionType collision);
void destroy_player();
void draw_player();
void jump();

#endif /* defined(__CGame__player__) */
