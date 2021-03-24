#include <stdio.h>
#include <engine.h>
#include <SDL2/SDL.h>

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
      printf("Error initializing SDL: %s\n", SDL_GetError());
      return 1;
    }

    gWindow = SDL_CreateWindow(
      "Hello Platformer!",
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      SCREEN_WIDTH, SCREEN_HEIGHT, 0
    );

    if(gWindow==NULL)
    {
      printf("Error while creating gWindow: %s\n", SDL_GetError());
      Engine_Quit();
      return 1;
    }

    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_FLAGS);
    if(gRenderer==NULL)
    {
      printf("Error while creating gRenderer: %s\n", SDL_GetError());
      Engine_Quit();
      return 1;
    }

    // Initialize
    Engine_Init();

    SDL_Event e;
    gState = ENGINE_RUNNING;
    do
    {
        // Continue if paused
        if(gState==ENGINE_PAUSED) continue;
        // pollEvents
        while(SDL_PollEvent(&e)!=0)
        {
            if(e.type==SDL_QUIT) gState = ENGINE_STOPPED;
            Engine_PollEvent(e);
        }

        // Update first then render
        Engine_Update();

        // Render ender black screen by default
        SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
        SDL_RenderClear(gRenderer);
        Engine_Render();
        SDL_RenderPresent(gRenderer);

    }while(gState!=ENGINE_STOPPED);

    Engine_Quit();
    return 0;
}
