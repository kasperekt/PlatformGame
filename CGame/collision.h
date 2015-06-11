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

typedef struct collision_data {
  int player_height, player_right;
  int player_x, player_y;
  int obstacle_height, obstacle_right;
  int obstacle_x, obstacle_y;
} CollisionData;

CollisionType detect_collision();

#endif /* defined(__CGame__collision__) */
