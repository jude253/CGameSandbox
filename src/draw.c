
#include <SDL2/SDL.h>
#include "init.h"
#include "defs.h"

const int SCREEN_DIVISOR = 10;
const int RECT_HEIGHT = SCREEN_HEIGHT / SCREEN_DIVISOR;
const int RECT_WIDTH = SCREEN_WIDTH / SCREEN_DIVISOR;
SDL_Rect rect;
void prepareScene(void)
{
    SDL_SetRenderDrawColor(app.renderer, 96, 128, 255, 255);
    SDL_RenderClear(app.renderer);
}

void drawRect(int x, int y) {
    rect.x = x;
    rect.y = y;
    rect.w = RECT_WIDTH;
    rect.h = RECT_HEIGHT;
    
    SDL_RenderDrawRect(app.renderer, &rect);
}

void drawBorderRects(void) {
    for (int i; i < SCREEN_DIVISOR; i++) {
        drawRect(i*RECT_WIDTH, 0);
        drawRect(i*RECT_WIDTH, SCREEN_HEIGHT-RECT_HEIGHT);
        drawRect(0, i*RECT_HEIGHT);
        drawRect(SCREEN_WIDTH-RECT_WIDTH, i*RECT_HEIGHT);
    }
}

void presentScene(void)
{   
    SDL_SetRenderDrawColor(app.renderer, 96, 0, 0, 255);
    drawBorderRects();
    SDL_RenderPresent(app.renderer);
}