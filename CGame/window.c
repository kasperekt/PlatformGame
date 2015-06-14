//
//  window.c
//  CGame
//
//  Created by Tomasz Kasperek on 31.05.2015.
//  Copyright (c) 2015 Tomasz Kasperek. All rights reserved.
//

#include "window.h"

int done = 0;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_TIMER *timer = NULL;

const int screen_width = 800;
const int screen_height = 600;
int FPS = 60;

int pressed_keys[ALLEGRO_KEY_MAX] = { 0 };

void abort_game(const char* message)
{
  fprintf(stderr, "%s\n", message);
  exit(1);
}

void init(const int fps)
{
  if(!al_init()) abort_game("Failed to initialize allegro");
  if(!al_install_keyboard()) abort_game("Failed to initialize keyboard");
  
  timer = al_create_timer(1.0 / fps);
  if(!timer) abort_game("Failed to create timer");
  
  al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_NOFRAME);
  display = al_create_display(screen_width, screen_height);
  if(!display) {
    al_destroy_timer(timer);
    abort_game("Failed to create display");
  }
  
  event_queue = al_create_event_queue();
  if(!event_queue) {
    al_destroy_timer(timer);
    al_destroy_display(display);
    abort_game("Failed to create event queue");
  }
  
  // Addons
  al_init_font_addon();
  al_init_ttf_addon();
  al_init_image_addon();

  al_register_event_source(event_queue, al_get_keyboard_event_source());
  al_register_event_source(event_queue, al_get_timer_event_source(timer));
  al_register_event_source(event_queue, al_get_display_event_source(display));
  
  done = false;
}

void game_shutdown()
{
  destroy_world();
  if(timer) al_destroy_timer(timer);
  if(display) al_destroy_display(display);
  if(event_queue) al_destroy_event_queue(event_queue);
}

void draw()
{
  al_clear_to_color(al_map_rgb(199, 242, 244));
  draw_world(pressed_keys);
  al_flip_display();
}

void game_loop()
{
  bool redraw = 1;
  al_start_timer(timer);
  init_world(screen_width, screen_height);
  
  while(!done) {
    ALLEGRO_EVENT event;
    al_wait_for_event(event_queue, &event);
    
    if(event.type == ALLEGRO_EVENT_TIMER) {
      redraw = 1;
    } else if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
      if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) done = 1;
      else pressed_keys[event.keyboard.keycode] = 1;
    } else if(event.type == ALLEGRO_EVENT_KEY_UP) {
      pressed_keys[event.keyboard.keycode] = 0;
    }
    
    if(redraw && al_is_event_queue_empty(event_queue)) {
      redraw = false;
      draw();
    }
  }
}