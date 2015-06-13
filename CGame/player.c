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

int current = 0;
int a = 0;
const int animation_steps = 11;
const float animation[animation_steps][2] = {
  {0, 0},
  {73, 0},
  {146, 0},
  {0, 98},
  {73, 98},
  {146, 98},
  {219, 0},
  {292, 0},
  {219, 98},
  {365, 0},
  {292, 98}
};

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
  
  player->image = al_load_bitmap("images/player.png");
  player->width = 72;
  player->height = 97;
  player->active = 0;
  player->direction = RIGHT;
}

void draw_player(bool *pressed, Collision collision)
{
  move_player(pressed, collision);
  
  al_draw_bitmap_region(player->image, animation[current][0], animation[current][1], player->width, player->height, player->x, player->y - player->height, player->direction);
//  al_draw_rectangle(player->x, player->y - player->size, player->x + player->size, player->y, al_map_rgb(255, 255, 255), 0);
}

void jump()
{
  player->jumping = 1;
  player->velocity_y = -9.0;
}

void move_player(bool *pressed, Collision collision)
{
  player->active = 0;
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
  
  if(pressed[ALLEGRO_KEY_RIGHT] && !(collision.type & BLOCKED_RIGHT)) {
    player->direction = RIGHT;
    player->active = 1;
    player->x += player->speed;
  }
  else if(pressed[ALLEGRO_KEY_LEFT] && !(collision.type & BLOCKED_LEFT)) {
    player->direction = LEFT;
    player->active = 1;
    player->x -= player->speed;
  }

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
  
  if(player->active) {
    a++;
    
    if(a == 2) {
      current = (current + 1) % 11;
      a = 0;
    }
  } else {
    current = 7;
  }
}

void destroy_player()
{
  al_destroy_bitmap(player->image);
  free(player);
}