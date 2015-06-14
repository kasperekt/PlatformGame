//
//  player.h
//  CGame
//
//  Created by Tomasz Kasperek on 31.05.2015.
//  Copyright (c) 2015 Tomasz Kasperek. All rights reserved.
//

#ifndef __CGame__player__
#define __CGame__player__

#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "collisiontype.h"
#include "gem.h"

/*
 * Enum mówiący o kierunku poruszania się gracza
 */
typedef enum {
  LEFT = ALLEGRO_FLIP_HORIZONTAL,
  RIGHT = 0
} PlayerDirection;

/*
 * Enum mówiący o położeniu gracza
 */
typedef enum {
  ON_FLOOR = (1 << 0),
  FALLING = (1 << 1),
  ON_PLATFORM = (1 << 2)
} PlayerPosition;

/*
 * Strukutra gracza, zawierająca dane położenia, stan gracza itp.
 */
struct player {
  float x, y;
  float speed;
  float velocity_y;
  float floor_limit;
  int height, width;
  int jumping;
  int active;
  int points;
  PlayerPosition position;
  PlayerDirection direction;
  ALLEGRO_BITMAP *image;
};

/*
 * Globalna zmienna dla gracza
 */
extern struct player* player;

/*
 * Inicializuje gracza
 */
void init_player(float x, float y, float floor_limit);
/*
 * Porusza gracza, zmienia jego położenia w osi x i y
 */
void move_player(int *pressed, Collisions collisions);
/*
 * Zwalnia pamięć gracza
 */
void destroy_player();
/*
 * Rysuje gracza
 */
void draw_player(int *pressed, Collisions collisions);
/*
 * Funkcja który wykonuje skok
 */
void jump();
/*
 * Animacja poruszania się postaci
 */
void animate();

#endif /* defined(__CGame__player__) */
