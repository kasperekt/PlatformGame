//
//  player.c
//  CGame
//
//  Created by Tomasz Kasperek on 31.05.2015.
//  Copyright (c) 2015 Tomasz Kasperek. All rights reserved.
//

#include "player.h"

struct player* player = NULL;

void init_player(float x, float y, float floor_limit)
{
  player = malloc(sizeof(*player));
  player->x = x;
  player->y = y;
  player->speed = 2;
  player->floor_limit = floor_limit;
  player->velocity_y = 0.0;
  player->on_ground = 1;
}

void draw_player()
{
  const float gravity = 0.5;
  
  if(!player->on_ground) {
    player->velocity_y += gravity;
    player->y += player->velocity_y;
    if(player->y > player->floor_limit) {
      player->on_ground = 1;
      player->y = player->floor_limit;
    }
  }
  
  al_draw_rectangle(player->x, player->y - 50, player->x + 10, player->y, al_map_rgb(0, 255, 0), 4);
}

void jump()
{
  player->on_ground = 0;
  player->velocity_y = -9.0;
}

void move_player(bool *pressed)
{
  if(pressed[ALLEGRO_KEY_RIGHT]) player->x += player->speed;
  else if(pressed[ALLEGRO_KEY_LEFT]) player->x -= player->speed;
  
  if(pressed[ALLEGRO_KEY_UP] && player->on_ground) jump();
}

void destroy_player()
{
  free(player);
}