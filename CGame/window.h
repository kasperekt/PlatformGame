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
#include <allegro5/allegro_image.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include "world.h"

/*
 * Zmienna informująca o tym, czy gra została ukończona
 */
extern int done;
extern ALLEGRO_DISPLAY *display;
extern ALLEGRO_EVENT_QUEUE *event_queue;
extern ALLEGRO_TIMER *timer;

/*
 * Szerokość i wysokość ekrany
 */
extern const int screen_width, screen_height;

/*
 * Inicializacja okienka do gry, uruchamianie potrzebnych modułów
 */
void init(const int fps);
/*
 * Opuszcza program razem z wyświetloną informacją o błędzie
 */
void abort_game(const char* message);
/*
 * Rysuje świat
 */
void draw();
/*
 * Zamyka gre, uruchamia funkcje zwalniające pamięć
 */
void game_shutdown();
/*
 * Pętla gry, dodaje klawisze do tablicy z wciśniętymi klawiszami, odświeża obraz
 */
void game_loop();

#endif /* defined(__CGame__window__) */
