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
  tmp->next = NULL;
  
  if(!crates) {
    crates = tmp;
  } else {
    crates->next = tmp;
  }
}

void draw_crates()
{
  struct crate* it = crates;
  while(it) {
    al_draw_rectangle(it->x, it->y - it->size, it->x + it->size, it->y, al_map_rgb(0, 0, 255), 4);
    it = it->next;
  }
}

void destroy_crates()
{
  struct crate* tmp = crates;
  
  while(tmp) {
    crates = tmp->next;
    free(tmp);
    tmp = crates;
  }
}