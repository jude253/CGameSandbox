
#include <SDL2/SDL.h>
#include "defs.h"
#include "structs.h"

App app;

void initSDL(void)
{
    int rendererFlags, windowFlags;

    rendererFlags = SDL_RENDERER_ACCELERATED;

    windowFlags = 0;

    // Initialize app data before game starts.
    app.frameStart = 0;
    app.renderFrameSeconds = 0.0f;
    app.fps = 0.0f;
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    app.window = SDL_CreateWindow("CGameSandbox", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags
    );

    if (!app.window)
    {
        printf("Failed to open %d x %d window: %s\n", 
            SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError()
        );
        exit(1);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);

    if (!app.renderer)
    {
        printf("Failed to create renderer: %s\n", SDL_GetError());
        exit(1);
    }
}