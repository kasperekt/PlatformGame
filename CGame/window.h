//
//  window.h
//  CGame
//
//  Created by Tomasz Kasperek on 31.05.2015.
//  Copyright (c) 2015 Tomasz Kasperek. All rights reserved.
//

#ifndef __CGame__window__
#define __CGame__window__

#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include "world.h"

extern bool done;
extern ALLEGRO_DISPLAY *display;
extern ALLEGRO_EVENT_QUEUE *event_queue;
extern ALLEGRO_TIMER *timer;
extern ALLEGRO_FONT *main_font;

extern const int screen_width, screen_height;

void init(const int fps);
void abort_game(const char* message);
void draw();
void game_shutdown();
void game_loop();

#endif /* defined(__CGame__window__) */
