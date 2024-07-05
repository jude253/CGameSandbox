#include <SDL2/SDL.h>
#include "init.h"

SDL_Point MOUSE_POSITION;

void doInput(void)
{
    SDL_GetMouseState(
        &MOUSE_POSITION.x,
        &MOUSE_POSITION.y
    );
    SDL_Log("Mouse position: x=%i y=%i",
        MOUSE_POSITION.x, MOUSE_POSITION.y
    );

    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                exit(0);
                break;
            default:
                break;
        }
    }
}