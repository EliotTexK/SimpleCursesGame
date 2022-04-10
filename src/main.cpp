#ifndef MAIN_CPP
#define MAIN_CPP

#include "main.h"
using namespace constants;

std::vector<GameObject *> gameObjects;

void renderMap() {
    for (int x = 0; x < LEVEL_SIZE_X; x++) {
        for (int y = 0; y < LEVEL_SIZE_Y; y++) {
            GameObject *draw = MapHandler::getObjectAtPos(x, y);
            if (draw != nullptr) {
                mvaddch(y, x, draw->display);
            } else {
                mvaddch(y, x, '.');
            }
        }
    }
}

int main() {
    srand(time(NULL));  // seed prng

    initscr();      // start ncurses
    start_color();  // start color mode
    curs_set(0);    // don't display the cursor
    noecho();       // don't echo input characters to the terminal
    cbreak();       // don't buffer characters before carriage return

    // init MessageHandler after starting ncurses!
    MessageHandler::init();
    MapHandler::initMap();
    EventHandler::initEventTimeline();

    // add some random objects
    // TODO: refactor into some kind of level-generation object
    for (int i = 0; i < MAX_EVENTS-25; i++) {
        Walker *toAdd = new Walker(rand() % LEVEL_SIZE_X, rand() % LEVEL_SIZE_Y);
        gameObjects.push_back(toAdd);
        MapHandler::addMapPosition(toAdd);
    }

    // game loop
    while (true) {
        renderMap();
        refresh();
        // inputHandler can decide whether or not to quit the game
        if (InputHandler::recieveInput(getch())) break;
        EventHandler::progressTime();
    }
    endwin();  // end ncurses
}

#endif