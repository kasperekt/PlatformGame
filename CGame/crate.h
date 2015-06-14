//
//  crate.h
//  CGame
//
//  Created by Tomasz Kasperek on 01.06.2015.
//  Copyright (c) 2015 Tomasz Kasperek. All rights reserved.
//

#ifndef __CGame__crate__
#define __CGame__crate__

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

/*
 * Struktura dla skrzyni
 */
struct crate {
  float x, y;
  int height, width;
  ALLEGRO_BITMAP *image;
  struct crate *next;
};

extern struct crate* crates;

/*
 * Dodawanie nowej skrzyni
 */
void add_crate(float x, float y);
/*
 * Zwalnianie pamięci dla skrzyni
 */
void destroy_crates();
/*
 * Rysowanie skrzyni
 */
void draw_crates(struct crate *c);

#endif /* defined(__CGame__crate__) */
