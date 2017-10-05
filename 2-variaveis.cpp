#include <stdio.h>
#include "ilpgame.h"

int cont;

void init() {
	cont 	= 0;
}

void destroy() {
	printf("# Total de chamadas a funcao draw = %d\n", cont);
}

void processEvent(SDL_Event event) {
  if (isQuitEvent(event))
    endGameLoop();
}

void update() {
	cont++;
}

void draw() {
	printf("%d\n",cont);
}

int main(int argc, char *argv[]) {
  initSDL();
  gameLoop();
  return 0;
}