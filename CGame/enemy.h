//
//  enemy.h
//  CGame
//
//  Created by Tomasz Kasperek on 14.06.2015.
//  Copyright (c) 2015 Tomasz Kasperek. All rights reserved.
//

#ifndef __CGame__enemy__
#define __CGame__enemy__

#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

/*
 * Enum mówiący o kierunku poruszania się wroga
 */
typedef enum {
  ENEMY_LEFT = 0,
  ENEMY_RIGHT = ALLEGRO_FLIP_HORIZONTAL
} EnemyDirection;

/*
 * Struktura dla wroga, jego prędkość, możliwy dystans do przebycia itp. (stack)
 */
typedef struct enemy {
  float x, y;
  float speed;
  float distance;
  int range;
  int animation_counter;
  int width, height;
  int frame;
  ALLEGRO_BITMAP *image;
  EnemyDirection direction;
  struct enemy *next;
} Enemy;

extern Enemy* enemies;

/*
 * Dodawanie wroga na stos
 */
void add_enemy(float x, float y, float speed, int range);
/*
 * Przesuwanie wroga
 */
void move_enemy(Enemy *e);
/*
 * Rysowanie wrogów
 */
void draw_enemies(Enemy *e);
/*
 * Zwalnianie pamięci wrogów
 */
void destroy_enemies();

#endif /* defined(__CGame__enemy__) */
