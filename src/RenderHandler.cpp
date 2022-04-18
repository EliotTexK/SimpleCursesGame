#ifndef RENDER_HANDLER_CPP
#define RENDER_HANDLER_CPP

#include "RenderHandler.h"
using namespace constants;

int RenderHandler::centerX;
int RenderHandler::centerY;

// pulls objects from the Map and renders them in screen space
void RenderHandler::renderMap(int _centerX, int _centerY) {
    centerX = _centerX;
    centerY = _centerY;
    for (int x = 0; x < SCREEN_SIZE_X; x++) {
        for (int y = 0; y < SCREEN_SIZE_Y; y++) {
            MapObject *draw =
                MapHandler::getObjectAtPos(centerX - HALF_SCREEN_SIZE_X + x,
                                           centerY - HALF_SCREEN_SIZE_Y + y);
            if (draw != nullptr) {
                mvaddch(y, x, draw->display);
            } else {
                mvaddch(y, x, '.');
            }
        }
    }
    refresh();
}
// does a "highlight" effect on the specified position
void RenderHandler::highlight(int x, int y, char display) {
    attron(A_REVERSE);
    mvaddch(y - centerY + HALF_SCREEN_SIZE_Y, x - centerX + HALF_SCREEN_SIZE_X, display);
    attroff(A_REVERSE);
    refresh();
}

#endif