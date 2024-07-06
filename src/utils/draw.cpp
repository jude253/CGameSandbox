
#include <SDL2/SDL.h>
#include "init.h"
#include "defs.h"
#include "input.h"
#include "colors.h"
#include "gameObjects/clickSquare.h"

const int SCREEN_DIVISOR = 10;
const int RECT_HEIGHT = SCREEN_HEIGHT / SCREEN_DIVISOR;
const int RECT_WIDTH = SCREEN_WIDTH / SCREEN_DIVISOR;

void setRenderDrawColor(Color color) {
    SDL_SetRenderDrawColor(app.renderer, 
    color.r, 
    color.g, 
    color.b, 
    color.a
    );
}

void prepareScene(void)
{
    setRenderDrawColor(BACKGROUND_COLOR);
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

void drawGrid(void) {
    SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);
    for (int i = 0; i < SCREEN_DIVISOR; i++) {
        for (int j = 0; j < SCREEN_DIVISOR; j++) {
            drawRect(i*RECT_WIDTH, j*RECT_HEIGHT);
        }
    }
}

void drawVertLine(int x, int y, int h) {
    SDL_RenderDrawLine(app.renderer, x, y, x, y+h);
}

/*
Draw vertically parallel trapezoid from x_lt to x_rt-- Left to Right.
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


void drawBorder(void) {

    // Top
    setRenderDrawColor(BLACK);
    SDL_Rect top;
    top.x = 0;
    top.y = 0;
    top.w = SCREEN_WIDTH;
    top.h = RECT_HEIGHT;
    SDL_RenderFillRect(app.renderer, &top);

    // Bottom
    SDL_Rect bottom;
    bottom.x = 0;
    bottom.y = SCREEN_HEIGHT-RECT_HEIGHT;
    bottom.w = SCREEN_WIDTH;
    bottom.h = RECT_HEIGHT;
    SDL_RenderFillRect(app.renderer, &bottom);

    
    // Sides:
    setRenderDrawColor(DARK_RED);
    
    // Left
    drawVerticalTrapezoid(
        0, 0,             RECT_WIDTH, RECT_HEIGHT,
        0, SCREEN_HEIGHT, RECT_WIDTH, SCREEN_HEIGHT-RECT_HEIGHT
    );

    // Right
    drawVerticalTrapezoid(
        SCREEN_WIDTH-RECT_WIDTH, RECT_HEIGHT,               SCREEN_WIDTH, 0,
        SCREEN_WIDTH-RECT_WIDTH, SCREEN_HEIGHT-RECT_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT
    );
}

void presentScene(void)
{   
    drawGrid();
    
    SDL_Rect mouse_rect;
    mouse_rect.x = app.mousePosition.x;
    mouse_rect.y = app.mousePosition.y;
    mouse_rect.w = RECT_WIDTH;
    mouse_rect.h = RECT_HEIGHT;

    SDL_RenderDrawRect(app.renderer, &mouse_rect);

    ClickSquare clickSquare;
    clickSquare.l = 100;
    clickSquare.color = BLUE;
    clickSquare.position.x=200;
    clickSquare.position.y=200;
    clickSquare.drawRect.h=clickSquare.l;
    clickSquare.drawRect.w=clickSquare.l;
    clickSquare.drawRect.x=clickSquare.position.x;
    clickSquare.drawRect.y=clickSquare.position.y;
    setRenderDrawColor(BLUE);
    SDL_RenderFillRect(app.renderer, &clickSquare.drawRect);

    drawBorder();
    SDL_RenderPresent(app.renderer);
}