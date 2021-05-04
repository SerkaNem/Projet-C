#include "Fonctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void Rules(SDL_Window* fenetre) {
	SDL_Renderer* renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_Event event;
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, IMG_Load("Graphisme/Rules.jpg")); 
	SDL_Rect position = {0, 0, 900, 900};

	while (1) {
		while(SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_QUIT: exit(-1);
				case SDL_MOUSEBUTTONDOWN: 
					if (event.button.x >= 40 && event.button.x <= 193 && event.button.y >= 26 && event.button.y <= 150) {
						SDL_DestroyTexture(texture);
						SDL_DestroyRenderer(renderer);
						return;
					}
					break;
				default: break;
			}
		}
		SDL_RenderCopy(renderer, texture, NULL, &position);
		SDL_RenderPresent(renderer);
		SDL_Delay(33);
	}
}