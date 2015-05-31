//
//  player.c
//  CGame
//
//  Created by Tomasz Kasperek on 31.05.2015.
//  Copyright (c) 2015 Tomasz Kasperek. All rights reserved.
//

#include "player.h"

struct player* player = NULL;

void init_player(float x, float y)
{
  player = malloc(sizeof(*player));
  player->x = x;
  player->y = y;
  player->speed = 2;
}

void draw_player()
{
  al_draw_rectangle(player->x, player->y, player->x + 10, player->y + 10, al_map_rgb(0, 255, 0), 4);
}

void move_player(bool *pressed)
{
  if(pressed[ALLEGRO_KEY_RIGHT]) player->x += player->speed;
  else if(pressed[ALLEGRO_KEY_LEFT]) player->x -= player->speed;
  
  if(pressed[ALLEGRO_KEY_UP]) player->y += 1;
}

void destroy_player()
{
  free(player);
}