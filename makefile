CFLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer -Wall
CC = @gcc

all: annonce

annonce :
	@clear
	@echo -e '\n*****************************************************************************************************************\n'
	@echo -e 'Bonjour et Bienvenue sur le projet de VINCENT Esteban et de PELISSIER Théo.\n'
	@echo -e 'Faites :\n'
	@echo 'make pour revoir ce message (Ca sert à rien ! ^^)'
	@echo 'make install pour installer les librairies SDL2 nécessaires dans le cas où vous ne les possédez pas.'
	@echo 'make build pour compiler le projet'
	@echo 'make run pour exécuter le projet'
	@echo -e 'make scratch pour compiler et exécuter en une fois\n' 
	@echo -e '*******************************************************************************************************************\n'

build : Code/Bienvenue.o Code/Game.o Code/Mode.o Code/Restart.o Code/Rules.o Code/Main.o
	clear
	$(CC) -o Actium $^ $(CFLAGS)
	@rm Code/*.o 

run :
	@clear
	@./Actium
	@clear
	@rm Actium 

install : 
	@clear
	@echo 'Votre machine va être mise à jour pour pouvoir installer les bibliothèques SDL2.'
	@echo 'Si vous ne voulez pas, vous pouvez toujours faire Ctrl + C pour annuler la démarche'
	@sleep 5
	@sudo apt install libsdl2-dev libsdl2-gfx-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-net-dev libsdl2-ttf-dev
	@sudo apt upgrade && sudo apt update
	@clear

scratch : build run 