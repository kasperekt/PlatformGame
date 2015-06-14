//
//  gem.h
//  CGame
//
//  Created by Tomasz Kasperek on 13.06.2015.
//  Copyright (c) 2015 Tomasz Kasperek. All rights reserved.
//

#ifndef __CGame__gem__
#define __CGame__gem__

#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

/*
 * Struktura dla diamentu
 */
typedef struct gems {
  int gem_id;
  int x, y;
  int width, height;
  int points;
  ALLEGRO_BITMAP *image;
  struct gems *next;
} Gems;

extern Gems *gems;

/*
 * Dodawanie diamentu na liste diamentów
 */
void add_gem(int x, int y, int points);
/*
 * Usuwanie diamentu z listy
 */
void remove_gem(int gem_id);
/*
 * Zwalnianie pamięci dla diamentów
 */
void destroy_gems();
/*
 * Rysowanie diamentów
 */
void draw_gems(Gems *gem);

#endif /* defined(__CGame__gem__) */
