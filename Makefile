²CC=gcc
CFLAGS=-Wall

INCLUDES = -Iinclude #-Idevel/SDL2/include
LIBRARIES = #-Ldevel/SDL2/lib
LINKER= -lSDL2main -lSDL2 -lm

SRC=src/
DEBUG=debug/

OBJ=program.exe

MOTD="Daily Commit from Makefile"

all: compile run
compile:
	echo Compiling sources ...
	$(CC)  $(SRC)*.c $(INCLUDES) $(LIBRARIES) $(CFLAGS) $(LINKER) -o $(DEBUG)$(OBJ)
run:
	echo Starting $(OBJ) ...
	./$(DEBUG)$(OBJ)
upload:
	git add .
	git commit -m $(MOTDsrc/engine.c:2:10: fatal error: SDL2/SDL.h: No such file or directory
	git push origin master
