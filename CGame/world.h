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
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "player.h"

void init_world();
void draw_world(const int width, const int height);
void destroy_world();

#endif /* defined(__CGame__world__) */
