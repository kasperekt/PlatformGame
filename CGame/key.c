//
//  key.c
//  CGame
//
//  Created by Tomasz Kasperek on 14.06.2015.
//  Copyright (c) 2015 Tomasz Kasperek. All rights reserved.
//

#include "key.h"

Key *key = NULL;

void add_key(int x, int y)
{
  key = malloc(sizeof(*key));
  key->x = x;
  key->y = y;
  key->image = al_load_bitmap("images/key.png");
  key->width = al_get_bitmap_width(key->image);
  key->height = al_get_bitmap_height(key->image);
}

void draw_key()
{
  if(key) {
    al_draw_bitmap(key->image, key->x, key->y - key->height, 0);
  }
}

void destroy_key()
{
  if(key) {
    al_destroy_bitmap(key->image);
    free(key);
  }
}