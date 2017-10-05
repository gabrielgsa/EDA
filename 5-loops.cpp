#include <stdio.h>
#include "ilpgame.h"

int 	pos;

float 	velocidade;

void init() {
	pos = 0;
	velocidade = 0.0;
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
		    	case SDLK_DOWN	:	if (velocidade > 0) 
		    							velocidade -= 1.0;
		    						break;
		    	case SDLK_UP	:	if (velocidade <= 40) 
		    							velocidade += 1.0;
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

int i;

	for (i = 0 ; i < 41 ; i++)
		if (i == velocidade)
			printf("X");
		else
			printf(".");
	printf("\n");

	printf("%d\n", pos);
}

int main(int argc, char *argv[]) {
  initSDL();
  gameLoop();
  return 0;
}