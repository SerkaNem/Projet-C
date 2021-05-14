#include "Fonctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int Bienvenue (SDL_Window* fenetre) {
	SDL_Renderer* renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_Event event;
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, IMG_Load("Graphisme/Bienvenue.jpg")); 
	SDL_Rect position = {0, 0, 900, 900}; 
	Mix_PlayMusic(Mix_LoadMUS("Son/Bienvenue.mp3"), 1); 

	while(1) {
		while(SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT: exit(-1);
				case SDL_MOUSEBUTTONDOWN:
					if (event.button.x >= 110 && event.button.x <= 376 && event.button.y >= 613 && event.button.x <= 678) {
						SDL_DestroyTexture(texture);
						SDL_DestroyRenderer(renderer);
						return 0;
					}
					if (event.button.x >= 494 && event.button.x <= 800 && event.button.y >= 625 && event.button.y <= 684) {
						SDL_DestroyTexture(texture);
						SDL_DestroyRenderer(renderer);
						return 1;
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