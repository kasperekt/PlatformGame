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
  NONE_COLLISION = 0,
  KILL_ENEMY = (1 << 0),
  KILL_PLAYER = (1 << 1),
  BLOCKED_RIGHT = (1 << 2),
  BLOCKED_LEFT = (1 << 3),
  BLOCKED_DOWN = (1 << 4),
  BLOCKED_UP = (1 << 5)
} CollisionType;

typedef struct collision {
  int x, y;
  CollisionType type;
} Collision;

typedef struct {
  int gem_id;
  int points;
} GemCollision;

typedef struct {
  int finished;
  GemCollision gem;
  Collision world;
} Collisions;

#endif
