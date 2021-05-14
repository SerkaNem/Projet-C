#include <SDL2/SDL.h>

void Game(SDL_Window* fenetre);
int Restart(SDL_Window* fenetre);
int Bienvenue(SDL_Window* fenetre);
void Rules(SDL_Window* fenetre);
int Mode(SDL_Window* fenetre);
void pastString (char Wait[], int position);
void TabIsTab ();
void permuter (int appui);
void Game(SDL_Window* fenetre);
void affichageLogoDebut(SDL_Window* fenetre);
int verification();
void melange();
int changeIsAllowed(int appui);
int estDejaPris (int rand, int Tab[], int taille); 