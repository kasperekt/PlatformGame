//
//  world.h
//  CGame
//
//  Created by Tomasz Kasperek on 31.05.2015.
//  Copyright (c) 2015 Tomasz Kasperek. All rights reserved.
//

#ifndef __CGame__world__
#define __CGame__world__

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "player.h"
#include "crate.h"
#include "collision.h"
#include "gem.h"
#include "key.h"
#include "enemy.h"

/*
 * Struktura świata, zawiera dane na temat:
 * - położenia "podłogi" i ziemii
 * - szerokość i wysokość ekranu
 * - szerokość mapy
 * - timer liczący czas gry
 */
struct world {
  float floor, ground;
  int width, height;
  int map_width, map_height;
  float game_timer;
  ALLEGRO_BITMAP *image;
  ALLEGRO_BITMAP *grass;
};

/*
 * Tworzy świat, dodaje graczy, przeszkody itp.
 */
void init_world(const int width, const int height);
/*
 * Ładuje mapę z pliku tekstowego
 */
void load_map(const char *filename);
/*
 * Dodaje element mapy na podstawie podanego stringu z danymi
 */
void add_element(char *data);
/*
 * Odświeża położenie kamery, jeśli gracz wychodzi dalej poza ekran
 */
float camera_update(float x, int width);
/*
 * Restartuje stan gry, dodaje od nowa graczy, elementy itp.
 */
void reset_game();
/*
 * Rysuje tekstury podłoża
 */
void draw_floor();
/*
 * Rysuje teksture trawy
 */
void draw_grass();
/*
 * Przelicza zdobyte punkty na podstawie czasu
 */
void count_points();
/*
 * Rysuje wynik
 */
void draw_points(int finished);
/*
 * Rysuje cały świat
 */
void draw_world(int *pressed);
/*
 * Dealokuje pamięc
 */
void destroy_world();

#endif /* defined(__CGame__world__) */
