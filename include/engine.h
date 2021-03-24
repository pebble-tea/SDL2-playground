#define FPS 60
#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 600
#define SCREEN_TITLE  "SDL2 Game Engine"

#define ENGINE_RENDERER_FLAGS SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC

#define ENGINE_RUNNING  2
#define ENGINE_PAUSED   1
#define ENGINE_STOPPED  0

typedef struct SDL_Window SDL_Window;
typedef struct SDL_Renderer SDL_Renderer;
typedef union  SDL_Event SDL_Event;

typedef unsigned char uint8_t;

SDL_Window*   gWindow;
SDL_Renderer* gRenderer;

uint8_t gState;

void Engine_Init();
void Engine_Update();
void Engine_Render();
void Engine_PollEvent(SDL_Event);
void Engine_Quit();
