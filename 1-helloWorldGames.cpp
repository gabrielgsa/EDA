#include <stdio.h>
#include "ilpgame.h"

void init() {
	printf("init\n");
}

void destroy() {
	printf("destroy\n");
}

void processEvent(SDL_Event event) {
  if (isQuitEvent(event))
    endGameLoop();
}

void update() {
	printf("update...\n");
}

void draw() {
	printf("draw...\n");
}

int main(int argc, char *argv[]) {
  initSDL();
  printf("Hello World, estrutura de dados com games!\n");
  gameLoop();
  return 0;
}