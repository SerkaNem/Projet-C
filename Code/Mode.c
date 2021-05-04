#include "Fonctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>

int Mode(SDL_Window* fenetre) {
	SDL_Renderer* renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_Event event;
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, IMG_Load("Graphisme/Mode.jpg")); 
	SDL_Rect position = {0, 0, 900, 900};
	Mix_Music* music = Mix_LoadMUS("Son/Choix.mp3"); 
	Mix_PlayMusic(music, 1); 

	while (1) {
		while(SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT: exit(-1);
				case SDL_MOUSEBUTTONDOWN:
					if (event.button.x >= 136 && event.button.x <= 330 && event.button.y >= 300 && event.button.y <= 470) {
						SDL_DestroyTexture(texture);
						SDL_DestroyRenderer(renderer);
						return 1;
					}
					if (event.button.x >= 486 && event.button.x <= 763 && event.button.y >= 301 && event.button.y <= 471) {
						SDL_DestroyTexture(texture);
						SDL_DestroyRenderer(renderer);
						return 2;
					}
					if (event.button.x >= 106 && event.button.x <= 332 && event.button.y >= 610 && event.button.y <= 781) {
						SDL_DestroyTexture(texture);
						SDL_DestroyRenderer(renderer);
						return 3;
					}
					if (event.button.x >= 498 && event.button.x <= 767 && event.button.y >= 613 && event.button.y <= 791) {
						SDL_DestroyTexture(texture);
						SDL_DestroyRenderer(renderer);
						return 4;
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