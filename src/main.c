#include <stdio.h>
#include <engine.h>
#include <SDL2/SDL.h>

SDL_Window* gWindow;
SDL_Renderer* gRenderer;
uint8_t gState;

int main()
{
    // Initialize SDL2 Subsystems
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    // Create new gWindow
    gWindow = SDL_CreateWindow( SCREEN_TITLE, SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_OPENGL);
    if (gWindow == NULL)
    {
        SDL_Log("Unable to create gWindow : %s", SDL_GetError());
        return 1;
    }

    // Create new gRenderer
    gRenderer = SDL_CreateRenderer(gWindow, -1, ENGINE_RENDERER_FLAGS);
    if(gRenderer == NULL)
    {
        SDL_Log("Unable to create gRenderer : %s", SDL_GetError());
        return 1;
    }

    SDL_Event e;


    Engine_Start();

    gState = ENGINE_RUNNING;
    while (gState != ENGINE_STOPPED)
    {
        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {break;}
            Engine_PollEvent(e);
        }

        // Engine_Update
        // Here we will use all physics, logic related functionalities
        Engine_Update();

        SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255); // draw black background by default
        SDL_RenderClear(gRenderer);

        // Engine_Render
        // Here we wil use all gfx related funcitonalities
        Engine_Render();

        SDL_RenderPresent(gRenderer);
    }

    // Destroy all SDL2 subsystems and quit applicaiton
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    SDL_Quit();
    return 0;
}
