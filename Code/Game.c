#include "Fonctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>

char image[9][22];
int Tableau[9];
int black = 8;
int mode;
char WaitNombre[9][22] = {"Graphisme/1.jpg", "Graphisme/2.jpg", "Graphisme/3.jpg", 
						  "Graphisme/4.jpg", "Graphisme/5.jpg", "Graphisme/6.jpg", 
						  "Graphisme/7.jpg", "Graphisme/8.jpg", "Graphisme/Noir.jpeg"};

char WaitImage[9][22] = {"Graphisme/1.png", "Graphisme/2.png", "Graphisme/3.png", 
						 "Graphisme/4.png", "Graphisme/5.png", "Graphisme/6.png", 
						 "Graphisme/7.png", "Graphisme/8.png", "Graphisme/Noir.jpeg"};

void TabIsTab () {
	int index;
	if(mode == 1 || mode == 2) {
		for (int i = 0; i < 9; i++) {
			index = Tableau[i];
			pastString(WaitImage[index], i);
		}
	} else {
		for (int i = 0; i < 9; i++) {
			index = Tableau[i];
			pastString(WaitNombre[index], i);
		}
	}
}

void pastString (char Wait[], int position) {
	int i;
	for (i = 0; Wait[i] != '\0'; i++) image[position][i] = Wait[i];
	image[position][i] = '\0';
}

void permuter (int appui) {
	Tableau[black] = Tableau[appui];
	Tableau[appui] = 8;
	black = appui;
	TabIsTab();
}

int estDejaPris (int rand, int Tab[], int taille) {
	for (int i = 0; i < taille; i++) {
		if(Tab[i] == rand) return 0;
	}
	return 1;
}

void melange() {
	for (int i = 0; i < 8; i++) {
		Tableau[i] = rand() % 8;
		if(!(estDejaPris(Tableau[i], Tableau, i))) i--;
	}
	Tableau[8] = 8;
	TabIsTab();
}

int verification() {
	for (int i = 0; i < 8; i++) {
		if(Tableau[i+1] <= Tableau[i]) return 0;
	}
	return 1;
}

void affichageLogoDebut(SDL_Window* fenetre) {
	SDL_Renderer* renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_Event event;
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, IMG_Load("Graphisme/Début.jpg")); 
	SDL_Rect position = {0, 0, 900, 900}; 
	Mix_PlayMusic(Mix_LoadMUS("Son/Jouer.mp3"), 1); 

	while(1) {
		while(SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT: exit(-1);
				case SDL_MOUSEBUTTONDOWN:
					SDL_DestroyTexture(texture);
					SDL_DestroyRenderer(renderer);
					return;
				default: break;
			}
		}
		SDL_RenderCopy(renderer, texture, NULL, &position);
		SDL_RenderPresent(renderer);
		SDL_Delay(33);
	}
}

void affichageLogoFin(SDL_Window* fenetre) {
	SDL_Renderer* renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_Event event;
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, IMG_Load("Graphisme/Win.jpg")); 
	SDL_Rect position = {0, 0, 900, 900};
	Mix_PlayMusic(Mix_LoadMUS("Son/Win.mp3"), 1); 

	while(1) {
		while(SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT: exit(-1);
				case SDL_MOUSEBUTTONDOWN:
					SDL_DestroyTexture(texture);
					SDL_DestroyRenderer(renderer);
					return;
				default: break;
			}
		}
		SDL_RenderCopy(renderer, texture, NULL, &position);
		SDL_RenderPresent(renderer);
		SDL_Delay(33);
	}
}

int changeIsAllowed(int appui) {
	if ((mode % 2) == 1) {
		switch(appui) {
			case 0:
				if (black == 1 || black == 3 || black == 4) return 1;
				break;
			case 1:
				if (black == 0 || black == 3 || black == 4 || black == 5 || black == 2) return 1;
				break;
			case 2:
				if(black == 1 || black == 5 || black == 4) return 1;
				break;
			case 3:
				if (black == 1 || black == 0 || black == 4 || black == 6 || black == 7) return 1;
				break;
			case 4:
				return 1;
			case 5:
				if (black == 1 || black == 2 || black == 4 || black == 8 || black == 7) return 1;
				break;
			case 6:
				if (black == 3 || black == 7 || black == 4) return 1;
				break;
			case 7:
				if (black == 3 || black == 5 || black == 4 || black == 8 || black == 6) return 1;
				break;
			case 8:
				if (black == 5 || black == 7 || black == 4) return 1;
				break;
		}
	}
	else {
		switch(appui) {
			case 0:
				if (black == 1 || black == 3) return 1;
				break;
			case 1:
				if (black == 0 || black == 4 || black == 2) return 1;
				break;
			case 2:
				if(black == 1 || black == 5) return 1;
				break;
			case 3:
				if (black == 0 || black == 4 || black == 6) return 1;
				break;
			case 4:
				if(black == 1 || black == 3 || black == 5 || black == 7) return 1;
				break;
			case 5:
				if (black == 2 || black == 4 || black == 8) return 1;
				break;
			case 6:
				if (black == 3 || black == 7) return 1;
				break;
			case 7:
				if (black == 4 || black == 8 || black == 6) return 1;
				break;
			case 8:
				if (black == 5 || black == 7) return 1;
				break;
		}
	}
	return 0;
} 

void Game(SDL_Window* fenetre) {
	int appui;
	mode = Mode(fenetre); 
	if(mode == 1 || mode == 2) affichageLogoDebut(fenetre);
	melange();

	SDL_Renderer* renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	SDL_Event event;
	SDL_Texture* mesTextures[9];
	SDL_Rect position[9];

	for (int i = 0; i < 9; i++) {
		position[i].h = 300; position[i].w = 300;
		position[i].x = 300*(i%3); position[i].y = 300*(i/3);
		mesTextures[i] = SDL_CreateTextureFromSurface(renderer, IMG_Load(image[i]));
	}

	while (1) {
		while (SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_QUIT: exit(-1);
				case SDL_MOUSEBUTTONDOWN:
					appui = ((event.button.x / 300) + (3*(event.button.y / 300)));
					if(changeIsAllowed(appui)) {
						permuter(appui);
						for (int i = 0; i < 9; i++) mesTextures[i] = SDL_CreateTextureFromSurface(renderer, IMG_Load(image[i]));
					}
					if (verification() == 1) {
						for (int i = 0; i < 9; i++) SDL_DestroyTexture(mesTextures[i]);
						SDL_DestroyRenderer(renderer);
						if(mode == 1 || mode == 2) affichageLogoFin(fenetre);
						return;
					}
					break;
				default: break;
			}
		}	
		for (int i = 0; i < 9; i++) SDL_RenderCopy(renderer, mesTextures[i], NULL, &position[i]);
		SDL_RenderPresent(renderer);
		SDL_Delay(33);
	}
}