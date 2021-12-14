# SFML paths (change this before compiling on your system)
SFMLINC = path/to/sfml/include
SFMLLIB = path/to/sfml/lib

# RapidXML path
RXML = path/to/RapidXML

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

# Project title (executable name)
TITLE = Block_breaker

OBJ = main.o game.o animatedsprite.o hitbox.o ray.o zoomableview.o button.o \
			checkbox.o guibar.o guitext.o nextstatebutton.o radiobutton.o \
			radiobuttonarray.o scrollbar.o mainmenu.o game_state.o resourcemanager.o \
			settingsmanager.o viewmanager.o

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
	g++ -c $(SRC)main.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) -I$(SRC) -I$(GUI) -I$(GMST) -I$(UTIL) -I$(MNGR)

game.o: $(SRC)game.cpp $(SRC)game.h $(GUI)guitext.h $(SRC)constants.h \
				$(SRC)gamestate.h $(GMST)mainmenu.h
	g++ -c $(SRC)game.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(SRC) -I$(GUI) -I$(GMST) -I$(UTIL) -I$(MNGR)


# Util classes
animatedsprite.o: $(UTIL)animatedsprite.cpp $(UTIL)animatedsprite.h
	g++ -c $(UTIL)animatedsprite.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(UTIL)

hitbox.o: $(UTIL)hitbox.cpp $(UTIL)hitbox.h
	g++ -c $(UTIL)hitbox.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) -I$(UTIL)

ray.o: $(UTIL)ray.cpp $(UTIL)ray.h $(SRC)constants.h $(UTIL)hitbox.h
	g++ -c $(UTIL)ray.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) -I$(UTIL) -I$(SRC)

zoomableview.o: $(UTIL)zoomableview.cpp $(UTIL)zoomableview.h $(SRC)constants.h \
								$(MNGR)settingsmanager.h
	g++ -c $(UTIL)zoomableview.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(UTIL) -I$(SRC) -I$(MNGR)


# GUI classes
button.o: $(GUI)button.cpp $(GUI)button.h $(UTIL)animatedsprite.h \
					$(GUI)guitext.h
	g++ -c $(GUI)button.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(GUI) -I$(UTIL)

checkbox.o: $(GUI)checkbox.cpp $(GUI)checkbox.h $(UTIL)animatedsprite.h \
						$(GUI)guitext.h
	g++ -c $(GUI)checkbox.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(GUI) -I$(UTIL)

guibar.o: $(GUI)guibar.cpp $(GUI)guibar.h
	g++ -c $(GUI)guibar.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) -I$(GUI)

guitext.o: $(GUI)guitext.cpp $(GUI)guitext.h
	g++ -c $(GUI)guitext.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) -I$(GUI)

nextstatebutton.o: $(GUI)nextstatebutton.cpp $(GUI)nextstatebutton.h \
									 $(UTIL)animatedsprite.h $(GUI)guitext.h $(SRC)gamestate.h
	g++ -c $(GUI)nextstatebutton.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(GUI) -I$(UTIL) -I$(SRC)

radiobutton.o: $(GUI)radiobutton.cpp $(GUI)radiobutton.h $(UTIL)animatedsprite.h \
							 $(GUI)guitext.h
	g++ -c $(GUI)radiobutton.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(GUI) -I$(UTIL)

radiobuttonarray.o: $(GUI)radiobuttonarray.cpp $(GUI)radiobuttonarray.h \
										$(GUI)radiobutton.h
	g++ -c $(GUI)radiobuttonarray.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(GUI) -I$(UTIL)

scrollbar.o: $(GUI)scrollbar.cpp $(GUI)scrollbar.h $(UTIL)animatedsprite.h
	g++ -c $(GUI)scrollbar.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(GUI) -I$(UTIL)


# Gamestate classes
mainmenu.o: $(GMST)mainmenu.cpp $(GMST)mainmenu.h $(GUI)guitext.h \
						$(SRC)gamestate.h $(MNGR)resourcemanager.h $(SRC)constants.h \
						$(MNGR)settingsmanager.h $(GUI)nextstatebutton.h
	g++ -c $(GMST)mainmenu.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(GMST) -I$(GUI) -I$(SRC) -I$(MNGR) -I$(UTIL)

game_state.o: $(GMST)game_state.cpp $(GMST)game_state.h
	g++ -c $(GMST)game_state.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(GMST) -I$(GUI) -I$(SRC) -I$(MNGR) -I$(UTIL)


# Manager classes
resourcemanager.o: $(MNGR)resourcemanager.cpp $(MNGR)resourcemanager.h \
									 $(UTIL)animatedsprite.h
	g++ -c $(MNGR)resourcemanager.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(MNGR) -I$(UTIL)

settingsmanager.o: $(MNGR)settingsmanager.cpp $(MNGR)settingsmanager.h \
									 $(UTIL)keyboardcontrols.h
	g++ -c $(MNGR)settingsmanager.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(MNGR) -I$(UTIL)

viewmanager.o: $(MNGR)viewmanager.cpp $(MNGR)viewmanager.h $(UTIL)zoomableview.h \
							 $(SRC)constants.h
	g++ -c $(MNGR)viewmanager.cpp -isystem $(SFMLINC) $(SFML) $(OPTIONS) \
			-I$(MNGR) -I$(UTIL) -I$(SRC)
