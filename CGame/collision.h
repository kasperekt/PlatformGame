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
#include "key.h"
#include "enemy.h"

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

int detect_key_collision(CollisionData c);
int detect_enemy_collision(CollisionData c);
Collision detect_world_collision(CollisionData c, int map_width);
GemCollision detect_gem_collision(CollisionData c);
Collisions detect_collisions(int map_width);
CollisionResult collision_right(CollisionData c);
CollisionResult collision_left(CollisionData c);
CollisionResult collision_down(CollisionData c);
CollisionResult collision_up(CollisionData c);

#endif /* defined(__CGame__collision__) */
