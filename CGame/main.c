#include <stdlib.h>
#include "window.h"

int main(int argc, char **argv) {
  init(60);
  game_loop();
  game_shutdown();
  
  return 0;
}
