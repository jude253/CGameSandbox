#include <SDL2/SDL.h>
#include "init.h"

void doInput(void)
{
    SDL_GetMouseState(
        &app.mousePosition.x,
        &app.mousePosition.y
    );
    SDL_Log("Mouse position: x=%i y=%i",
        app.mousePosition.x, app.mousePosition.y
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