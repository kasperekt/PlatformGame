//
//  collision.c
//  CGame
//
//  Created by Tomasz Kasperek on 01.06.2015.
//  Copyright (c) 2015 Tomasz Kasperek. All rights reserved.
//

#include "collision.h"

CollisionResult collision_right(CollisionData c)
{
  CollisionResult result;
  result.has = c.player_right >= c.obstacle_x &&
               c.player_y > c.obstacle_height &&
               c.player_height <= c.obstacle_y &&
               c.player_x < c.obstacle_right;
  
  return result;
}

CollisionResult collision_left(CollisionData c)
{
  CollisionResult result;
  result.has = c.player_x <= c.obstacle_right &&
               c.player_y > c.obstacle_height &&
               c.player_height <= c.obstacle_y &&
               c.player_x >= c.obstacle_right;
  
  return result;
}

CollisionResult collision_down(CollisionData c)
{
  CollisionResult result;
  result.has = c.player_y >= c.obstacle_height &&
               c.player_right > c.obstacle_x &&
               c.player_height <= c.obstacle_y &&
               c.player_y < c.obstacle_y &&
               c.player_x < c.obstacle_right;
  result.y = c.obstacle_height;
  
  return result;
}

CollisionResult collision_up(CollisionData c)
{
  CollisionResult result;
  result.has = c.player_right > c.obstacle_x &&
               c.player_y > c.obstacle_height &&
               c.player_height <= c.obstacle_y &&
               c.player_height > c.obstacle_height &&
               c.player_x < c.obstacle_right;
  
  return result;
}

Collision detect_collision()
{
  Collision collision;
  collision.type = NONE_COLLISION;
  collision.x = 0;
  collision.y = 0;
  
  struct crate* it = crates;
  
  CollisionData c;
  c.player_right = player->x + player->width;
  c.player_height = player->y - player->height;
  c.player_x = player->x;
  c.player_y = player->y;
  
  CollisionResult result;
  
  while(it) {
    c.obstacle_right = it->x + it->size;
    c.obstacle_height = it->y - it->height;
    c.obstacle_x = it->x;
    c.obstacle_y = it->y;
    
    result = collision_down(c);
    if(result.has) {
      collision.type |= BLOCKED_DOWN;
      collision.y = result.y;
    }
    
    result = collision_right(c);
    if(result.has) {
      collision.type |= BLOCKED_RIGHT;
    }
    
    result = collision_left(c);
    if(result.has) {
      collision.type |= BLOCKED_LEFT;
    }
    
    result = collision_up(c);
    if(result.has) {
      collision.type |= BLOCKED_UP;
    }
    
    it = it->next;
  }
  
  return collision;
}