CC=gcc
CFLAGS=-Wall

INCLUDES = -Iinclude -Idevel\SDL2\include
LIBRARIES = -Ldevel\SDL2\lib
LINKER= -lmingw32 -lSDL2main -lSDL2

SRC=src/
DEBUG=debug/

OBJ=program.exe

all: compile run
compile:
	echo Compiling sources ...
	$(CC)  $(SRC)*.c $(INCLUDES) $(LIBRARIES) $(CFLAGS) $(LINKER) -o $(DEBUG)$(OBJ)
run:
	echo Starting $(OBJ) ...
	./$(DEBUG)$(OBJ)
