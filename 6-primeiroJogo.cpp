#include <stdio.h>
#include "ilpgame.h"

float 	velocidadeX,
		velocidadeY;

float 	posX, 
		posY;

int 	w = 600,
		h = 600;

SDL_Surface *img;

void init() {
	velocidadeX =
	velocidadeY = 0.0;

	posX = w / 2.0; 
	posY = h / 2.0;

	img = loadImage("../Assets/hero.png");
}

void destroy() {
	SDL_FreeSurface(img);
}

void processEvent(SDL_Event event) {

	SDL_Keycode keycode = event.key.keysym.sym;

	if (isQuitEvent(event))
		endGameLoop();
	else
		if (event.type == SDL_KEYDOWN) {

		    switch (keycode) {
		    	case SDLK_DOWN		:	velocidadeY += 0.05;
		    							break;
		    	case SDLK_UP		:	velocidadeY -= 0.05;
		    							break;
		    	case SDLK_LEFT		:	velocidadeX -= 0.05;
		    							break;
		    	case SDLK_RIGHT		:	velocidadeX += 0.05;
		    							break;
		    	case '0'			:	velocidadeX =
		    							velocidadeY = 0.0;
		    							posX = w / 2.0;
										posY = h / 2.0;
		    							break;
				}
			}
}

void update() {
	posX = posX + velocidadeX;	
	posY = posY + velocidadeY;	
}

void draw() {
  drawImage(img, posX, posY);
}

int main(int argc, char *argv[]) {

	if (argc > 1)
		w = atoi(argv[1]);

	if (argc > 2)
		h = atoi(argv[2]);

	initSDL(w,h);
	gameLoop();
	return 0;
}