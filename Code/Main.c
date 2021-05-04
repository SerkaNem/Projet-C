#include "Fonctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <time.h>

int main(int argc, char const *argv[]) {
	srand(time(NULL));
	int choix;
	SDL_Init(SDL_INIT_EVERYTHING);
	Mix_OpenAudio(96000, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	SDL_Window* fenetre = SDL_CreateWindow("Le jeu du Taquin", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 900, 0);
	SDL_SetWindowIcon(fenetre, IMG_Load("Graphisme/Icone.png"));
	do {
		do {
			choix = Bienvenue(fenetre);
			if(choix == 1) Rules(fenetre);
		} while (choix == 1);
		Game(fenetre);
	} while (Restart(fenetre) == 1);
	SDL_DestroyWindow(fenetre);
	Mix_CloseAudio(); // Quitter correctement SDL_Mixer
	SDL_Quit();
	return 0;
}			