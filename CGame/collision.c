//
//  collision.c
//  CGame
//
//  Created by Tomasz Kasperek on 01.06.2015.
//  Copyright (c) 2015 Tomasz Kasperek. All rights reserved.
//

#include "collision.h"
int ii = 0;

CollisionResult collision_right(CollisionData c)
{
  CollisionResult result;
  result.has = c.player_right >= c.obstacle_x &&
               c.player_y > c.obstacle_height &&
               c.player_height < c.obstacle_y &&
               c.player_x < c.obstacle_x;
  
  return result;
}

CollisionResult collision_left(CollisionData c)
{
  CollisionResult result;
  result.has = c.player_x <= c.obstacle_right &&
               c.player_y > c.obstacle_height &&
               c.player_height < c.obstacle_y &&
               c.player_right > c.obstacle_right;
  
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

Collisions detect_collisions(int map_width)
{
  Collisions result;
  
  CollisionData c;
  c.player_right = player->x + player->width;
  c.player_height = player->y - player->height;
  c.player_x = player->x;
  c.player_y = player->y;
  
  result.world = detect_world_collision(c, map_width);
  result.gem = detect_gem_collision(c);
  result.finished = detect_key_collision(c);
  
  return result;
}

int detect_key_collision(CollisionData c)
{
  if(!key) return 0;
  c.obstacle_right = key->x + key->width;
  c.obstacle_height = key->y - key->height;
  c.obstacle_x = key->x;
  c.obstacle_y = key->y;
  
  if(collision_down(c).has) return 1;
  if(collision_up(c).has) return 1;
  if(collision_left(c).has) return 1;
  if(collision_right(c).has) return 1;
  
  return 0;
}

GemCollision detect_gem_collision(CollisionData c)
{
  Gems *it = gems;
  
  GemCollision collision;
  collision.gem_id = 0;
  collision.points = 0;
  
  CollisionResult result;
  
  while(it) {
    c.obstacle_right = it->x + it->width;
    c.obstacle_height = it->y - it->height;
    c.obstacle_x = it->x;
    c.obstacle_y = it->y;
    
    result = collision_down(c);
    if(result.has) {
      collision.gem_id = it->gem_id;
      collision.points = it->points;
      break;
    }
    
    result = collision_up(c);
    if(result.has) {
      collision.gem_id = it->gem_id;
      collision.points = it->points;
      break;
    }
    
    result = collision_left(c);
    if(result.has) {
      collision.gem_id = it->gem_id;
      collision.points = it->points;
      break;
    }
    
    result = collision_right(c);
    if(result.has) {
      collision.gem_id = it->gem_id;
      collision.points = it->points;
      break;
    }
    
    it = it->next;
  }
  
  return collision;
}

Collision detect_world_collision(CollisionData c, int map_width)
{
  struct crate* it = crates;
  
  Collision collision;
  collision.type = NONE_COLLISION;
  collision.x = 0;
  collision.y = 0;
  
  CollisionResult result;
  
  // Map boundaries
  if(c.player_x <= 0) {
    collision.type |= BLOCKED_LEFT;
    return collision;
  } else if(c.player_right >= map_width) {
    collision.type |= BLOCKED_RIGHT;
    return collision;
  }
  
  while(it) {
    c.obstacle_right = it->x + it->width;
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
      printf("Coll: %d\n", ii++);
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