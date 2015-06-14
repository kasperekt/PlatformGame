//
//  enemy.c
//  CGame
//
//  Created by Tomasz Kasperek on 14.06.2015.
//  Copyright (c) 2015 Tomasz Kasperek. All rights reserved.
//

#include "enemy.h"

Enemy *enemies = NULL;

void add_enemy(float x, float y, float speed, int range)
{
  Enemy *tmp = malloc(sizeof(*tmp));
  tmp->x = x;
  tmp->y = y;
  tmp->speed = speed;
  tmp->range = range;
  tmp->distance = 0;
  tmp->image = al_load_bitmap("images/enemy.png");
  tmp->width = 50;
  tmp->height = 28;
  tmp->direction = ENEMY_RIGHT;
  tmp->animation_counter = 0;
  tmp->frame = 0;
  tmp->next = NULL;
  
  if(!enemies) {
    enemies = tmp;
  } else {
    tmp->next = enemies;
    enemies = tmp;
  }
}

void move_enemy(Enemy *e)
{
  if(e->direction == ENEMY_RIGHT) e->x += e->speed;
  else e->x -= e->speed;
  
  e->distance += e->speed;
  
  if(e->distance >= e->range) {
    e->distance = 0;
    e->direction ^= ENEMY_RIGHT;
  }
}

void draw_enemies(Enemy *e)
{
  if(e) {
    move_enemy(e);
    if(e->animation_counter++ > 15) {
      e->animation_counter = 0;
      e->frame = (e->frame + 50) % 100;
    }
    
    al_draw_bitmap_region(e->image, e->frame, 0, e->width, e->height, e->x, e->y - e->height, e->direction);
    draw_enemies(e->next);
  }
}

void destroy_enemies()
{
  Enemy *tmp = enemies;
  
  while(tmp) {
    enemies = tmp->next;
    al_destroy_bitmap(tmp->image);
    free(tmp);
    tmp = enemies;
  }
  
  enemies = NULL;
}