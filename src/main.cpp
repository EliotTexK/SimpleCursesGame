#ifndef MAIN_CPP
#define MAIN_CPP

#include "main.h"
using namespace constants;

void render() {
    // render the objects at the locations
    for (int x = 0; x < LEVEL_SIZE_X; x++) {
        for (int y = 0; y < LEVEL_SIZE_Y; y++) {
            GameObject * draw = mapHandler.getObjectAtPos(x,y);
            if (draw != nullptr) {
                mvaddch(draw->y, draw->x, draw->display);
            } else {
                mvaddch(y, x, '.');
            }
        }
    }
    refresh();
}

int main() {
    srand(time(NULL)); // seed prng

    mapHandler = MapHandler();
    eventHandler = EventHandler();

    // add some random objects
    for (int i = 0; i < 10 ; i ++) {
        Walker *toAdd = new Walker(
            rand() % LEVEL_SIZE_X,
            rand() % LEVEL_SIZE_Y,
            &mapHandler,
            &eventHandler
        );
        gameObjects.push_back(toAdd);
        mapHandler.addMapPosition(toAdd);
    }

    initscr();     // start ncurses
    start_color(); // start color mode
    curs_set(0);   // don't display the cursor
    noecho();
    cbreak();

    // render, then advance game loop
    while (getch() != 'q') {
        render();
        eventHandler.progressTime();
    }
    endwin(); // end ncurses
}

#endif