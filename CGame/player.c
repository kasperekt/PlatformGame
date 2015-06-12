//
//  player.c
//  CGame
//
//  Created by Tomasz Kasperek on 31.05.2015.
//  Copyright (c) 2015 Tomasz Kasperek. All rights reserved.
//

#include "player.h"

struct player* player = NULL;
const float gravity = 0.5;

void init_player(float x, float y, float floor_limit)
{
  player = malloc(sizeof(*player));
  player->x = x;
  player->y = y;
  player->size = 20;
  player->speed = 2;
  player->floor_limit = floor_limit;
  player->velocity_y = 0.0;
  player->jumping = 0;
  player->position |= ON_FLOOR;
}

void draw_player(bool *pressed, Collision collision)
{
  move_player(pressed, collision);
  
  al_draw_rectangle(player->x, player->y - player->size, player->x + player->size, player->y, al_map_rgb(255, 255, 255), 0);
}

void jump()
{
  player->jumping = 1;
  player->velocity_y = -9.0;
}

void move_player(bool *pressed, Collision collision)
{
  if(collision.type & BLOCKED_DOWN) {
    player->jumping = 0;
    player->position = ON_PLATFORM;
    player->y = collision.y;
  } else {
    player->position |= FALLING;
  }
  
  if(collision.type & BLOCKED_UP) {
    player->velocity_y = 0;
  }
  
  if(pressed[ALLEGRO_KEY_RIGHT] && !(collision.type & BLOCKED_RIGHT)) player->x += player->speed;
  else if(pressed[ALLEGRO_KEY_LEFT] && !(collision.type & BLOCKED_LEFT)) player->x -= player->speed;

  if(pressed[ALLEGRO_KEY_UP] && !player->jumping) jump();

  
  if(!(player->position & ON_FLOOR) && (player->position & FALLING) && player->y < player->floor_limit && !player->jumping) {
    player->velocity_y += gravity;
    player->y += player->velocity_y;
    
    if(player->y >= player->floor_limit) {
      player->position = ON_FLOOR;
      player->y = player->floor_limit;
    }
  } else if(player->jumping) {
    player->velocity_y += gravity;
    player->y += player->velocity_y;
    
    if(player->y >= player->floor_limit) {
      player->jumping = 0;
      player->y = player->floor_limit;
    }
  }
}

void destroy_player()
{
  free(player);
}