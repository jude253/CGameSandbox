#include <SDL2/SDL.h>
#include "defs.h"
#include "math.h"

SDL_Point getRandomPoint(void) {
    SDL_Point point;
    point.x = rand() % (SCREEN_WIDTH  + 1);
    point.y = rand() % (SCREEN_HEIGHT + 1);
    return point;
}