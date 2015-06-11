//
//  collisiontype.h
//  CGame
//
//  Created by Tomasz Kasperek on 01.06.2015.
//  Copyright (c) 2015 Tomasz Kasperek. All rights reserved.
//

#ifndef CGame_collisiontype_h
#define CGame_collisiontype_h

typedef enum {
  KILL_ENEMY,
  KILL_PLAYER,
  BLOCKED_RIGHT,
  BLOCKED_LEFT,
  BLOCKED_DOWN,
  BLOCKED_UP,
  NONE_COLLISION
} CollisionType;

typedef struct collision {
  int x, y;
  CollisionType type;
} Collision;

#endif
