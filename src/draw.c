
#include <SDL2/SDL.h>
#include "init.h"
#include "defs.h"

const int SCREEN_DIVISOR = 10;
const int RECT_HEIGHT = SCREEN_HEIGHT / SCREEN_DIVISOR;
const int RECT_WIDTH = SCREEN_WIDTH / SCREEN_DIVISOR;

SDL_Point mouse_position;

void prepareScene(void)
{
    SDL_SetRenderDrawColor(app.renderer, 96, 128, 255, 255);
    SDL_RenderClear(app.renderer);
}

void drawRect(int x, int y) {
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = RECT_WIDTH;
    rect.h = RECT_HEIGHT;
    
    SDL_RenderDrawRect(app.renderer, &rect);
}

void drawBorderRects(void) {
    for (int i = 0; i < SCREEN_DIVISOR; i++) {
        drawRect(i*RECT_WIDTH, 0);
        drawRect(i*RECT_WIDTH, SCREEN_HEIGHT-RECT_HEIGHT);
        drawRect(0, i*RECT_HEIGHT);
        drawRect(SCREEN_WIDTH-RECT_WIDTH, i*RECT_HEIGHT);
    }
}

void drawVertLine(int x, int y, int h) {
    SDL_RenderDrawLine(app.renderer, x, y, x, y+h);
}

/*
Draw vertically parallel trapezoid from x_lt to x_rt.
*/
void drawVerticalTrapezoid(
    int x_lt, int y_lt, int x_rt, int y_rt,
    int x_lb, int y_lb, int x_rb, int y_rb
    ) {
    int y_t;
    int y_b;
    for (int x = x_lt; x < x_rt; x++) {
        y_t = (int)(((float)(y_rt - y_lt) / (float)(x_rt - x_lt))*(float)(x-x_lt) + y_lt);
        y_b = (int)(((float)(y_rb - y_lb) / (float)(x_rb - x_lb))*(float)(x-x_lb) + y_lb);
        SDL_RenderDrawLine(app.renderer, x, y_t, x, y_b);
    }
    
}

void presentScene(void)
{   
    SDL_SetRenderDrawColor(app.renderer, 96, 0, 0, 255);
    drawBorderRects();

    drawVerticalTrapezoid(
        0, 0,             RECT_WIDTH, RECT_HEIGHT,
        0, SCREEN_HEIGHT, RECT_WIDTH, SCREEN_HEIGHT-RECT_HEIGHT
    );
    drawVerticalTrapezoid(
        SCREEN_WIDTH-RECT_WIDTH, RECT_HEIGHT,               SCREEN_WIDTH, 0,
        SCREEN_WIDTH-RECT_WIDTH, SCREEN_HEIGHT-RECT_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT
    );

    SDL_GetMouseState(
        &mouse_position.x,
        &mouse_position.y
    );

    SDL_Rect rect;
    rect.x = mouse_position.x;
    rect.y = mouse_position.y;
    rect.w = RECT_WIDTH;
    rect.h = RECT_HEIGHT;

    SDL_RenderDrawRect(app.renderer, &rect);
    SDL_Log("Mouse position: x=%i y=%i",
        mouse_position.x, mouse_position.y
    );

    SDL_RenderPresent(app.renderer);
}