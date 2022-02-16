# SFML paths (change this before compiling on your system)
SFMLINC = path/to/sfml/include
SFMLLIB = path/to/sfml/lib

# Options
SFML = -lsfml-graphics-s -lsfml-window-s -lsfml-audio-s -lsfml-network-s -lsfml-system-s \
	   -lfreetype -lopenal32 -lflac -lvorbisenc -lvorbisfile -lvorbis -logg -lws2_32 \
	   -lopengl32 -lwinmm -lgdi32 -D SFML_STATIC
OPTIONS = -std=c++17 -Wall -Weffc++ -Wextra -Wsign-conversion -Wpedantic

# Source structure
SRC  = ./src/
GMST = ./src/gamestate/
GUI  = ./src/gui/
MNGR = ./src/managers/
UTIL = ./src/util/
GMOB = ./src/gameobject/

# Project title (executable name)
TITLE = Block_breaker

OBJ = main.o game.o random.o \
		  animatedsprite.o \
			button.o guitext.o nextstatebutton.o \
			mainmenu.o game_state.o \
			resourcemanager.o settingsmanager.o \
			ball.o wall.o balldeletor.o ballgenerator.o block.o blockgenerator.o \
			extraballpowerup.o verticaldamagepowerup.o horizontaldamagepowerup.o \
			flipperpowerup.o ballcollider.o powerup.o arrow.o

# Output rules
output: $(OBJ)
	g++ $(OBJ) -o $(TITLE).exe -L$(SFMLLIB) -mwindows $(SFML)

debug: $(OBJ)
	g++ $(OBJ) -o $(TITLE)-debug.exe -g -L$(SFMLLIB) $(SFML)

linux: $(OBJ)
	g++ $(OBJ) -o $(TITLE) -lsfml-network -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

linux_debug: $(OBJ)
	g++ $(OBJ) -o $(TITLE)-debug -g -lsfml-network -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

clear:
	del $(OBJ)

linux_clear:
	rm $(OBJ)


# Main classes
main.o: $(SRC)main.cpp $(SRC)game.h
	g++ -c $(SRC)main.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(SRC) -I$(GUI) -I$(GMST) -I$(UTIL) -I$(MNGR)  -I$(GMOB)

game.o: $(SRC)game.cpp $(SRC)game.h $(GUI)guitext.h $(SRC)constants.h \
				$(SRC)gamestate.h $(GMST)mainmenu.h
	g++ -c $(SRC)game.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(SRC) -I$(GUI) -I$(GMST) -I$(UTIL) -I$(MNGR) -I$(GMOB)

random.o: $(SRC)random.cpp $(SRC)random.h
	g++ -c $(SRC)random.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(SRC)


# Util classes
animatedsprite.o: $(UTIL)animatedsprite.cpp $(UTIL)animatedsprite.h
	g++ -c $(UTIL)animatedsprite.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(UTIL)

# GUI classes
button.o: $(GUI)button.cpp $(GUI)button.h $(UTIL)animatedsprite.h \
					$(GUI)guitext.h
	g++ -c $(GUI)button.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(GUI) -I$(UTIL)

guitext.o: $(GUI)guitext.cpp $(GUI)guitext.h
	g++ -c $(GUI)guitext.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) -I$(GUI)

nextstatebutton.o: $(GUI)nextstatebutton.cpp $(GUI)nextstatebutton.h \
									 $(UTIL)animatedsprite.h $(GUI)guitext.h $(SRC)gamestate.h
	g++ -c $(GUI)nextstatebutton.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(GUI) -I$(UTIL) -I$(SRC)

# Gamestate classes
mainmenu.o: $(GMST)mainmenu.cpp $(GMST)mainmenu.h $(GUI)guitext.h \
						$(SRC)gamestate.h $(MNGR)resourcemanager.h $(SRC)constants.h \
						$(MNGR)settingsmanager.h $(GUI)nextstatebutton.h
	g++ -c $(GMST)mainmenu.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(GMST) -I$(GUI) -I$(SRC) -I$(MNGR) -I$(UTIL)

game_state.o: $(GMST)game_state.cpp $(GMST)game_state.h $(GMOB)ball.h \
						  $(GUI)guitext.h $(MNGR)resourcemanager.h $(SRC)constants.h \
							$(GMOB)block.h $(GMOB)blockgenerator.h
	g++ -c $(GMST)game_state.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(GMST) -I$(GUI) -I$(SRC) -I$(MNGR) -I$(UTIL) -I$(GMOB)


# Manager classes
resourcemanager.o: $(MNGR)resourcemanager.cpp $(MNGR)resourcemanager.h \
									 $(UTIL)animatedsprite.h
	g++ -c $(MNGR)resourcemanager.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(MNGR) -I$(UTIL)

settingsmanager.o: $(MNGR)settingsmanager.cpp $(MNGR)settingsmanager.h
	g++ -c $(MNGR)settingsmanager.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(MNGR) -I$(UTIL)

# Game object classes
ball.o: $(GMOB)ball.cpp $(GMOB)ball.h $(SRC)constants.h
	g++ -c $(GMOB)ball.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(GMOB) -I$(SRC)

wall.o: $(GMOB)wall.cpp $(GMOB)wall.h $(GMOB)ball.h $(SRC)constants.h
	g++ -c $(GMOB)wall.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(GMOB) -I$(SRC)

balldeletor.o: $(GMOB)balldeletor.cpp $(GMOB)balldeletor.h $(GMOB)ball.h \
							 $(SRC)constants.h
	g++ -c $(GMOB)balldeletor.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(GMOB) -I$(SRC) -I$(GUI) -I$(MNGR) -I$(UTIL)

ballgenerator.o: $(GMOB)ballgenerator.cpp $(GMOB)ballgenerator.h $(GMOB)ball.h \
								 $(SRC)constants.h $(MNGR)resourcemanager.h
	g++ -c $(GMOB)ballgenerator.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(GMOB) -I$(SRC) -I$(GUI) -I$(MNGR) -I$(UTIL)

block.o: $(GMOB)block.cpp $(GMOB)block.h $(GMOB)ball.h $(SRC)constants.h \
				 $(GUI)guitext.h $(SRC)random.h
	g++ -c $(GMOB)block.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(GMOB) -I$(SRC) -I$(GUI)

blockgenerator.o: $(GMOB)blockgenerator.cpp $(GMOB)blockgenerator.h $(GMOB)block.h \
								 	$(SRC)constants.h $(GMOB)ballgenerator.h $(MNGR)resourcemanager.h \
									$(SRC)random.h $(GMOB)extraballpowerup.h $(GMOB)verticaldamagepowerup.h \
									$(GMOB)horizontaldamagepowerup.h $(GMOB)flipperpowerup.h
	g++ -c $(GMOB)blockgenerator.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(GMOB) -I$(SRC) -I$(GUI) -I$(MNGR) -I$(UTIL) -I$(GUI)

extraballpowerup.o: $(GMOB)extraballpowerup.cpp $(GMOB)extraballpowerup.h \
										$(GMOB)block.h $(GMOB)ballgenerator.h
	g++ -c $(GMOB)extraballpowerup.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(GMOB) -I$(SRC) -I$(UTIL) -I$(GUI) -I$(MNGR)

verticaldamagepowerup.o: $(GMOB)verticaldamagepowerup.cpp $(GMOB)verticaldamagepowerup.h \
										$(GMOB)block.h $(GMOB)ballgenerator.h $(GMOB)blockgenerator.h
	g++ -c $(GMOB)verticaldamagepowerup.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(GMOB) -I$(SRC) -I$(UTIL) -I$(GUI) -I$(MNGR)

horizontaldamagepowerup.o: $(GMOB)horizontaldamagepowerup.cpp $(GMOB)horizontaldamagepowerup.h \
										$(GMOB)block.h $(GMOB)ballgenerator.h $(GMOB)blockgenerator.h
	g++ -c $(GMOB)horizontaldamagepowerup.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(GMOB) -I$(SRC) -I$(UTIL) -I$(GUI) -I$(MNGR)

flipperpowerup.o: $(GMOB)flipperpowerup.cpp $(GMOB)flipperpowerup.h \
										$(GMOB)block.h $(GMOB)ballgenerator.h $(GMOB)blockgenerator.h
	g++ -c $(GMOB)flipperpowerup.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(GMOB) -I$(SRC) -I$(UTIL) -I$(GUI) -I$(MNGR)

ballcollider.o: $(GMOB)ballcollider.cpp $(GMOB)ballcollider.h $(GMOB)ball.h
	g++ -c $(GMOB)ballcollider.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(GMOB) -I$(SRC)

powerup.o: $(GMOB)powerup.cpp $(GMOB)powerup.h $(GMOB)ball.h $(UTIL)animatedsprite.h
	g++ -c $(GMOB)powerup.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(GMOB) -I$(SRC) -I$(UTIL) -I$(GUI) -I$(MNGR)

arrow.o: $(GMOB)arrow.cpp $(GMOB)arrow.h $(MNGR)resourcemanager.h $(UTIL)animatedsprite.h
	g++ -c $(GMOB)arrow.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(GMOB) -I$(SRC) -I$(UTIL) -I$(GUI) -I$(MNGR)
