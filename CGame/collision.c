//
//  collision.c
//  CGame
//
//  Created by Tomasz Kasperek on 01.06.2015.
//  Copyright (c) 2015 Tomasz Kasperek. All rights reserved.
//

#include "collision.h"

int collision_right(CollisionData c)
{
  return c.player_right >= c.obstacle_x &&
         c.player_y > c.obstacle_height &&
         c.player_x < c.obstacle_right;
}

int collision_left(CollisionData c)
{
  return c.player_x <= c.obstacle_right &&
         c.player_y > c.obstacle_height &&
         c.player_x >= c.obstacle_right;
}

CollisionType detect_collision()
{
  CollisionType collision = NONE_COLLISION;
  struct crate* it = crates;
  
  CollisionData c;
  c.player_right = player->x + player->size;
  c.player_height = player->y - player->size;
  c.player_x = player->x;
  c.player_y = player->y;
  
  while(it) {
    c.obstacle_right = it->x + it->size;
    c.obstacle_height = it->y - it->size;
    c.obstacle_x = it->x;
    c.obstacle_y = it->y;
    
    if(collision_right(c)) {
      collision = BLOCKED_RIGHT;
      break;
    }
    
    if(collision_left(c)) {
      collision = BLOCKED_LEFT;
      break;
    }
    
    it = it->next;
  }
  
  return collision;
}