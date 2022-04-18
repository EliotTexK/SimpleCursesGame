#ifndef RENDER_HANDLER_H
#define RENDER_HANDLER_H

#include <ncurses.h>
#include "MapHandler.h"
#include "constants.h"
using namespace constants;

class RenderHandler {
    static const char HALF_SCREEN_SIZE_X = SCREEN_SIZE_X/2;
    static const char HALF_SCREEN_SIZE_Y = SCREEN_SIZE_Y/2;
    static int centerX, centerY;
   public:
    static void renderMap(int _centerX, int _centerY);
    static void highlight(int x, int y, char display);
};

#endif