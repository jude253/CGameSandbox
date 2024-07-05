#include <SDL2/SDL.h>

typedef struct {
    SDL_Renderer *renderer;
    SDL_Window *window;
    Uint64 frameStart;  // Frame start.  Intended to be set by SDL_GetPerformanceCounter()
    float renderFrameSeconds;  // Seconds to render current frame
    float fps;  // FPS calculated from previous frame start to current frame start
} App;