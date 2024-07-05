
#include <string.h>
#include "init.h"
#include "draw.h"
#include "input.h"
#include "defs.h"

void handleFrameStart(void) {
    Uint64 frameStart = SDL_GetPerformanceCounter();
    float frameStartToStartSeconds = (float)(frameStart - app.frameStart) / 
                                     (float)SDL_GetPerformanceFrequency();
    
    // Calculate fps from frame start to frame start. Hopefully this
    // will allow accurate frame calculation also in emscripten on web.
    app.fps = 1.0f/frameStartToStartSeconds;

    // Overwrite previous frame start with current frame start
    app.frameStart = frameStart;
}

void handleFrameEnd(void) {
    Uint64 renderEnd = SDL_GetPerformanceCounter();

    // Calculate how long it took to render current frame
    app.renderFrameSeconds = (float)(renderEnd - app.frameStart) / 
                             (float)SDL_GetPerformanceFrequency();
    
    // If not running in emscipten, delay start of next frame to target FPS:
#ifndef __EMSCRIPTEN__
    SDL_Delay(
        // Needs to be in MS
        floor((TARGET_SECONDS_PER_FRAME - app.renderFrameSeconds)*1000.0f)
    );
#endif
}

void renderFrame(void) {
    
    handleFrameStart();

    prepareScene();

    doInput();

    presentScene();

    handleFrameEnd();
    
}


int main(int argc, char *argv[])
{
    memset(&app, 0, sizeof(App));

    initSDL();

    // atexit(cleanup);

    while(1)
    {
        SDL_Log("FPS=%f", app.fps);
        renderFrame();
    }

    return 0;
}