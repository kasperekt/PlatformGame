//
//  gem.c
//  CGame
//
//  Created by Tomasz Kasperek on 13.06.2015.
//  Copyright (c) 2015 Tomasz Kasperek. All rights reserved.
//

#include "gem.h"

Gems *gems = NULL;

void add_gem(int x, int y, int points)
{
  Gems *tmp = malloc(sizeof(*tmp));
  tmp->x = x;
  tmp->y = y;
  tmp->points = points;
  tmp->image = al_load_bitmap("images/gem_red.png");
  tmp->width = al_get_bitmap_width(tmp->image);
  tmp->height = al_get_bitmap_height(tmp->image);
  tmp->next = NULL;
  
  Gems *it = gems;
  if(!it) {
    tmp->gem_id = 1;
    gems = tmp;
    gems->next = NULL;
  } else {
    while(it->next) {
      it = it->next;
    }
    
    tmp->gem_id = it->gem_id + 1;
    it->next = tmp;
  }
}

void remove_gem(int id)
{
  Gems *tmp = gems;
  Gems *to_delete = NULL;
  
  if(tmp->gem_id == id) {
    to_delete = tmp;
    gems = tmp->next;
    al_destroy_bitmap(to_delete->image);
    free(to_delete);
  } else {
    while(tmp->next) {
      if(tmp->next->gem_id == id) {
        to_delete = tmp->next;
        tmp->next = tmp->next->next;
        
        al_destroy_bitmap(to_delete->image);
        free(to_delete);
        return;
      }
      
      tmp = tmp->next;
    }
  }
}

void draw_gems(Gems *gem) {
  if(gem) {
    al_draw_bitmap(gem->image, gem->x, gem->y - gem->height, 0);
    draw_gems(gem->next);
  }
}

void destroy_gems()
{
  Gems *tmp = gems;
  
  while(tmp) {
    gems = tmp;
    tmp = tmp->next;
    
    al_destroy_bitmap(gems->image);
    free(gems);
  }
  
  gems = NULL;
}