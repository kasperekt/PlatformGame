//
//  key.h
//  CGame
//
//  Created by Tomasz Kasperek on 14.06.2015.
//  Copyright (c) 2015 Tomasz Kasperek. All rights reserved.
//

#ifndef __CGame__key__
#define __CGame__key__

#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

/*
 * Tworzy świat, dodaje graczy, przeszkody itp.
 */
typedef struct {
  int x, y;
  int width, height;
  ALLEGRO_BITMAP *image;
} Key;

extern Key* key;

/*
 * Dodawanie klucza (może być tylko 1)
 */
void add_key(int x, int y);
/*
 * Rysowanie klucza
 */
void draw_key();
/*
 * Zwalnianie pamięci dla klucza
 */
void destroy_key();

#endif /* defined(__CGame__key__) */
