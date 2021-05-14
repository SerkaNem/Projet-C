#include "Fonctions.h"
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
			if(choix) Rules(fenetre);
		} while (choix);
		Game(fenetre);
	} while (Restart(fenetre));
	SDL_DestroyWindow(fenetre);
	Mix_CloseAudio(); 
	SDL_Quit();
	return 0;
}			