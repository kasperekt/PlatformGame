//
//  collisiontype.h
//  CGame
//
//  Created by Tomasz Kasperek on 01.06.2015.
//  Copyright (c) 2015 Tomasz Kasperek. All rights reserved.
//

#ifndef CGame_collisiontype_h
#define CGame_collisiontype_h

/*
 * Enum mówiący o aktualnym statusie kolizji
 */
typedef enum {
  NONE_COLLISION = 0,
  BLOCKED_RIGHT = (1 << 0),
  BLOCKED_LEFT = (1 << 1),
  BLOCKED_DOWN = (1 << 2),
  BLOCKED_UP = (1 << 3)
} CollisionType;

/*
 * Strukutra dla kolizji
 */
typedef struct collision {
  int x, y;
  CollisionType type;
} Collision;

/*
 * Struktura dla kolizji między diamentem a graczem
 */
typedef struct {
  int gem_id;
  int points;
} GemCollision;

/*
 * Ogólna struktura wszystkich kolizji
 */
typedef struct {
  int finished;
  int touched_enemy;
  GemCollision gem;
  Collision world;
} Collisions;

#endif
