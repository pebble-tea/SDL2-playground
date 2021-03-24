#include <engine.h>
#include <SDL2/SDL.h>

// Engine Initialization
void Engine_Init(){}

// Engine Updates (TODO : dt)
void Engine_Update(){}

// Engine Render GFX
void Engine_Render(){}

// Event Handler
void Engine_PollEvent(SDL_Event e){}

// Destroy pointers then Quit Application
void Engine_Quit()
{
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    SDL_Quit();
}
