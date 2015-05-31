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
#include "player.h"

typedef enum {
  KILL_ENEMY,
  KILL_PLAYER,
  TOUCH_OBSTACLE,
  NONE
} CollisionType;

CollisionType detect_collision();

#endif /* defined(__CGame__collision__) */
