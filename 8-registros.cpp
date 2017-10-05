#include <stdio.h>
#include "ilpgame.h"

struct 	posicao 	{ 	float x;
						float y;
					};

struct posicao	v;
struct posicao 	p;

int 	w = 600,
		h = 600;

int 	imgIndex;

SDL_Surface *img[4];

void init() {
	
	p.x = w / 2.0; 
	p.y = h / 2.0;

	v.x =
	v.y = 0.0;

	imgIndex = 0;

	img[0] = loadImage("../Assets/walking1.png");
	img[1] = loadImage("../Assets/walking2.png");
	img[2] = loadImage("../Assets/walking3.png");
	img[3] = loadImage("../Assets/walking4.png");
}

void destroy() {
	int i;

	for(i = 0 ; i < 4 ; i++)
		SDL_FreeSurface(img[i]);
}

void processEvent(SDL_Event event) {

	SDL_Keycode keycode = event.key.keysym.sym;

	if (isQuitEvent(event))
		endGameLoop();
	else
		if (event.type == SDL_KEYDOWN) {

		    switch (keycode) {
		    	case SDLK_DOWN		:	v.y += 0.05;
		    							break;
		    	case SDLK_UP		:	v.y -= 0.05;
		    							break;
		    	case SDLK_LEFT		:	v.x -= 0.05;
		    							break;
		    	case SDLK_RIGHT		:	v.x += 0.05;
		    							break;

		    	case '0'			:	v.x =
		    							v.y = 0.0;
										p.x = w / 2.0; 
										p.y = h / 2.0;
		    							break;

		    	case '1'			:	imgIndex = 0;
		    							break;
		    	case '2'			:	imgIndex = 1;
		    							break;
		    	case '3'			:	imgIndex = 2;
		    							break;
		    	case '4'			:	imgIndex = 3;
		    							break;
				}
			}
}

void update() {
	p.x += v.x;	
	p.y += v.y;	
}

void draw() {
	cleanScreen(128, 128, 128);
	
	drawImage(img[imgIndex], p.x, p.y);
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