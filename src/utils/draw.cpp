#include <SDL2/SDL.h>
#include "init.h"
#include "drawHelperFunctions.h"
#include "defs.h"
#include "input.h"
#include "gameObjects/clickSquare.h"
#include "SDL_ttf.h"

void drawDebugGrid(void) {
    setRenderDrawColor(WHITE);
    for (int i = 0; i < SCREEN_DIVISOR; i++) {
        for (int j = 0; j < SCREEN_DIVISOR; j++) {
            drawRect(i*GRID_WIDTH, j*GRID_HEIGHT);
        }
    }
}

void drawBorder(void) {

    // Top
    setRenderDrawColor(BLACK);
    SDL_Rect top;
    top.x = 0;
    top.y = 0;
    top.w = SCREEN_WIDTH;
    top.h = GRID_HEIGHT;
    SDL_RenderFillRect(app.renderer, &top);

    // Bottom
    SDL_Rect bottom;
    bottom.x = 0;
    bottom.y = SCREEN_HEIGHT-GRID_HEIGHT;
    bottom.w = SCREEN_WIDTH;
    bottom.h = GRID_HEIGHT;
    SDL_RenderFillRect(app.renderer, &bottom);

    
    // Sides:
    setRenderDrawColor(DARK_RED);
    
    // Left
    drawVerticalTrapezoid(
        0, 0,             GRID_WIDTH, GRID_HEIGHT,
        0, SCREEN_HEIGHT, GRID_WIDTH, SCREEN_HEIGHT-GRID_HEIGHT
    );

    // Right
    drawVerticalTrapezoid(
        SCREEN_WIDTH-GRID_WIDTH, GRID_HEIGHT,               SCREEN_WIDTH, 0,
        SCREEN_WIDTH-GRID_WIDTH, SCREEN_HEIGHT-GRID_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT
    );
}

void prepareScene(void)
{
    setRenderDrawColor(BACKGROUND_COLOR);
    SDL_RenderClear(app.renderer);
}


// void renderText(void) {
//     TTF_Font *font = TTF_OpenFont("src/utils/font/SourceCodePro-Regular.ttf", 24);

//     SDL_Color white = {255, 255, 255};
//     SDL_Surface *surface = TTF_RenderText_Solid(font, "Hello World", white);
//     SDL_Texture *texture = SDL_CreateTextureFromSurface(app.renderer, surface);
//     int textWidth = surface->w;
//     int textHeight = surface->h;
//     SDL_FreeSurface(surface);
//     SDL_Rect rect;
//     rect.x = 0;
//     rect.y = 0;
//     rect.w = textWidth;
//     rect.h = textHeight;
//     SDL_RenderCopy(app.renderer, texture, NULL, &rect);
// }

void presentScene(void)
{   
    drawDebugGrid();
    
    SDL_Rect mouse_rect;
    mouse_rect.x = app.mousePosition.x;
    mouse_rect.y = app.mousePosition.y;
    mouse_rect.w = GRID_WIDTH;
    mouse_rect.h = GRID_HEIGHT;

    SDL_RenderDrawRect(app.renderer, &mouse_rect);
    
    for (int i = 0; i < CLICK_SQUARES_LIST.size(); i++) {
        ClickSquare cs = CLICK_SQUARES_LIST[i];
        drawClickSquare(app, cs);
    }
    drawBorder();
    SDL_RenderPresent(app.renderer);
}