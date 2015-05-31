//
//  collision.c
//  CGame
//
//  Created by Tomasz Kasperek on 01.06.2015.
//  Copyright (c) 2015 Tomasz Kasperek. All rights reserved.
//

#include "collision.h"

CollisionType detect_collision()
{
  CollisionType collision = NONE_COLLISION;
  struct crate* it = crates;
  
  while(it) {
    int player_right = player->x + player->size;
    
    int crate_right = it->x + it->size;
    int crate_height = it->y - it->size;
    
    if(player_right >= it->x && player->y > crate_height && player->x < crate_right) {
      collision = BLOCKED_RIGHT;
      break;
    }
    if(player->x <= crate_right && player->y > crate_height && player->x >= crate_right) {
      collision = BLOCKED_LEFT;
      break;
    }
    if(crate_height <= player->y) {
      collision = BLOCKED_DOWN;
      break;
    }
    
    it = it->next;
  }
  
  return collision;
}