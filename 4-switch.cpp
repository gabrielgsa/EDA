#include <stdio.h>
#include "ilpgame.h"

int 	pos;

float 	velocidade = 0.0;

void init() {
	pos = 0;
}

void destroy() {
	printf("Valor final de pos = %d\n", pos);
}

void processEvent(SDL_Event event) {

	SDL_Keycode keycode = event.key.keysym.sym;

	if (isQuitEvent(event))
		endGameLoop();
	else
		if (event.type == SDL_KEYDOWN) 

		    switch (keycode) {
		    	case SDLK_DOWN	:	velocidade -= 0.5;
		    						break;
		    	case SDLK_UP	:	velocidade += 0.5;
		    						break;
		    	default			: 	pos = 0;
		    						velocidade = 0;
		    						printf("*\n");
		    						break;
				}
}

void update() {
	pos += velocidade;
}

void draw() {
	printf("%d\n",pos);
}

int main(int argc, char *argv[]) {
  initSDL();
  gameLoop();
  return 0;
}