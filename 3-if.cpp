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

SDL_Keycode keycode;

	if (isQuitEvent(event))
		endGameLoop();
	
	keycode = event.key.keysym.sym;

	if (event.type == SDL_KEYDOWN) {

	    if (keycode == SDLK_DOWN) {
	    	velocidade -= 0.5;
	    	printf("vel = %f\n", velocidade);
	    	}
	    else {
	    	if (keycode == SDLK_UP) {
	    		velocidade += 0.5;
		    	printf("vel = %f\n", velocidade);
		    	}
		    }
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