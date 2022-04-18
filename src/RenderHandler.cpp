#ifndef RENDER_HANDLER_CPP
#define RENDER_HANDLER_CPP

#include <ncurses.h>
#include "MapHandler.h"
#include "constants.h"
using namespace constants;

struct RenderHandler {
    /* Searches the map's object array, and prints display characters
    // at their corresponding positions. If there's nothing in a space,
    // prints a period '.' Obviously, don't call this until you have
    // started ncurses.
    */
    inline static void renderMap() {
        for (int x = 0; x < LEVEL_SIZE_X; x++) {
            for (int y = 0; y < LEVEL_SIZE_Y; y++) {
                MapObject *draw = MapHandler::getObjectAtPos(x, y);
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
    inline static void highlight(int x, int y, char display) {
        attron(A_REVERSE);
        mvaddch(y, x, display);
        attroff(A_REVERSE);
        refresh();
    }
};

#endif