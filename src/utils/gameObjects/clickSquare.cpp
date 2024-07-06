#include <SDL2/SDL.h>
#include "../structs.h"
#include "../drawHelperFunctions.h"
#include <vector>
#include <stdbool.h>

class ClickSquare {

public:
    Color color;  // RGBA color
    SDL_Rect drawRect;  // Actual Rect used to draw onscreen.  Update with other attributes.
    int l;  // Edge length
    Point position;  // (x,y) upper left corner float coordinates -- truncate before drawing.
    Point velocity;  // (x,y) float velocity components
    Point acceleration;  // (x,y) float velocity components
    Uint64 drawTime;  // Draw time-- intended to be set by SDL_GetPerformanceCounter()
};

ClickSquare createClickSquare(int x, int y, int l, Color color) {
    ClickSquare clickSquare;
    clickSquare.l = l;
    clickSquare.color = color;
    clickSquare.position.x=(float)x;
    clickSquare.position.y=(float)y;
    clickSquare.drawRect.h=clickSquare.l;
    clickSquare.drawRect.w=clickSquare.l;
    clickSquare.drawRect.x=clickSquare.position.x;
    clickSquare.drawRect.y=clickSquare.position.y;
    return clickSquare;
}

std::vector<ClickSquare> CLICK_SQUARES_LIST;

void drawClickSquare(App app, ClickSquare clickSquare) {
    setRenderDrawColor(clickSquare.color);
    SDL_RenderFillRect(app.renderer, &clickSquare.drawRect);
}

bool deleteClickSquareIfClicked(App app) {
    for (int i=0; i<CLICK_SQUARES_LIST.size(); i++) {
        ClickSquare cs = CLICK_SQUARES_LIST[i];
        if (SDL_PointInRect(&app.mousePosition, &cs.drawRect)) {
            SDL_Log("CLICKED RECTANGLE!");
            CLICK_SQUARES_LIST.erase(CLICK_SQUARES_LIST.begin() + i );
            return 1;
        }
    }
    return 0;
}
