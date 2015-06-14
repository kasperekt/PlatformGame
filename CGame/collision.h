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

/*
 * Dane kolizji wymagane do sprawdzania czy taka kolizja istnieje
 */
typedef struct collision_data {
  int player_height, player_right;
  int player_x, player_y;
  int obstacle_height, obstacle_right;
  int obstacle_x, obstacle_y;
} CollisionData;

/*
 * Wynik kolizji
 */
typedef struct collision_result {
  int has;
  int x, y;
} CollisionResult;

/*
 * Wykrywa kolizje między graczem a kluczem (który kończy grę)
 */
int detect_key_collision(CollisionData c);
/*
 * Wykyrwa kolizję między graczem a wrogiem
 */
int detect_enemy_collision(CollisionData c);
/*
 * Wykrywa kolizje między graczem a obiektami na świecie
 */
Collision detect_world_collision(CollisionData c, int map_width);
/*
 * Wykrywa kolizję między graczem a diamentami do zbierania
 */
GemCollision detect_gem_collision(CollisionData c);
/*
 * Wykyrwa ogólnie kolizje
 */
Collisions detect_collisions(int map_width);
/*
 * Wykrywa kolizje z prawej strony
 */
CollisionResult collision_right(CollisionData c);
/*
 * Wykrywa kolizje z lewej strony
 */
CollisionResult collision_left(CollisionData c);
/*
 * Wykrywa kolizje z dołu
 */
CollisionResult collision_down(CollisionData c);
/*
 * Wykrywa kolizje z góry
 */
CollisionResult collision_up(CollisionData c);

#endif /* defined(__CGame__collision__) */
