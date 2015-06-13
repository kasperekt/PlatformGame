//
//  crate.c
//  CGame
//
//  Created by Tomasz Kasperek on 01.06.2015.
//  Copyright (c) 2015 Tomasz Kasperek. All rights reserved.
//

#include "crate.h"

struct crate* crates = NULL;

void add_crate(float x, float y)
{
  struct crate* tmp = malloc(sizeof(*tmp));
  tmp->x = x;
  tmp->y = y;
  tmp->size = 60;
  tmp->image = al_load_bitmap("images/box.png");
  tmp->width = al_get_bitmap_width(tmp->image);
  tmp->height = al_get_bitmap_height(tmp->image);
  tmp->next = NULL;
  
  if(!crates) {
    crates = tmp;
  } else {
    tmp->next = crates;
    crates = tmp;
  }
}

void draw_crates()
{
  struct crate* it = crates;
  while(it) {
    al_draw_bitmap(it->image, it->x, it->y - it->height, 0);
    it = it->next;
  }
}

void destroy_crates()
{
  struct crate* tmp = crates;
  
  while(tmp) {
    crates = tmp->next;
    al_destroy_bitmap(tmp->image);
    free(tmp);
    tmp = crates;
  }
}