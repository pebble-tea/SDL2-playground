#include <stdio.h>
#include <stdlib.h>

#include <engine.h>
#include <SDL2/SDL.h>


void ImportData(const char* filename)
{
	FILE *fp;
    	fp = fopen(filename, "r+");
	if(fp != NULL)
	{
		int size;
		fscanf(fp, "SIZE=%d", &size);
		SDL_Log("%d",size);
		SDL_Log("closing file");
		fclose(fp);
	}
}


void Engine_Start()
{
	ImportData("data/test.shape");
}


void Engine_Update(){}
void Engine_Render(){}
void Engine_PollEvent(SDL_Event e){}


