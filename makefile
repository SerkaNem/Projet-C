all: PROJET EXECUTION
code.o : Code/Bienvenue.c Code/Game.c Code/Mode.c Code/Restart.c Code/Rules.c Code/Fonctions.h
	@echo 'Pour le bon fonctionnement du projet, nous allons installer la bibliothèque SDL2 et mettre à jour la machine. Si vous ne voulez pas, faites un Ctrl + C.'
	@sleep 5
	@sudo apt install libsdl2-2.0-0 libsdl2-gfx-1.0-0 libsdl2-image-2.0-0 libsdl2-mixer-2.0-0 libsdl2-net-2.0-0 libsdl2-ttf-2.0-0 
	@sudo apt upgrade && sudo apt update && sudo apt upgrade 
	@clear 
	@gcc -c Code/Bienvenue.c -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lSDL2_mixer 
	@gcc -c Code/Game.c -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lSDL2_mixer
	@gcc -c Code/Restart.c -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lSDL2_mixer
	@gcc -c Code/Rules.c -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lSDL2_mixer
	@gcc -c Code/Mode.c -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lSDL2_mixer
main.o : Code/Main.c
	@gcc -c Code/Main.c -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lSDL2_mixer
PROJET : main.o code.o
	@gcc -o Actium Main.o Bienvenue.o Game.o Mode.o Restart.o Rules.o -lSDL2 -lSDL2_image -lSDL2_mixer
	@rm *.o

EXECUTION :
	@./Actium