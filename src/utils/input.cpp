#include "SDL.h"
#include "init.h"
#include "gameObjects/clickSquare.h"



void doInput(void)
{
    SDL_GetMouseState(
        &app.mousePosition.x,
        &app.mousePosition.y
    );
    

    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_MOUSEBUTTONDOWN:
                SDL_Log("Mouse position: x=%i y=%i",
                    app.mousePosition.x, app.mousePosition.y
                );
                deleteClickSquareIfClicked(app);
                break;
            default:
                break;
        }
    }
}