//
//  collision.h
//  CGame
//
//  Created by Tomasz Kasperek on 01.06.2015.
//  Copyright (c) 2015 Tomasz Kasperek. All rights reserved.
//

#ifndef __CGame__collision__
#define __CGame__collision__

#include <stdio.h>
#include "collisiontype.h"
#include "player.h"
#include "crate.h"
#include "gem.h"

typedef struct collision_data {
  int player_height, player_right;
  int player_x, player_y;
  int obstacle_height, obstacle_right;
  int obstacle_x, obstacle_y;
} CollisionData;

typedef struct collision_result {
  int has;
  int x, y;
} CollisionResult;

Collision detect_world_collision();
GemCollision detect_gem_collision();
Collisions detect_collisions();
CollisionResult collision_right(CollisionData c);
CollisionResult collision_left(CollisionData c);
CollisionResult collision_down(CollisionData c);
CollisionResult collision_up(CollisionData c);

#endif /* defined(__CGame__collision__) */
