#ifndef MAIN_CPP
#define MAIN_CPP

#include "main.h"
using namespace constants;

std::vector<MapObject *> gameObjects;
Controllable player;

void renderMap() {
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
    // TODO: refactor into some kind of level-generation
    for (int i = 0; i < 1; i++) {
        Wanderer *toAdd = new Wanderer(rand() % LEVEL_SIZE_X, rand() % LEVEL_SIZE_Y);
        gameObjects.push_back(toAdd);
    }

    // add the player
    player = Controllable(rand() % LEVEL_SIZE_X, rand() % LEVEL_SIZE_Y);
    MapHandler::addMapPosition(&player);

    // you MUST make sure to instantiate the player before you call InputHandler::itit
    InputHandler::init(&player);

    // game loop
    while (true) {
        renderMap();
        refresh();
        // inputHandler can decide whether or not to quit the game
        if (InputHandler::recieveInput()) break;
        // ideally, time should progress according to the "player",
        // or whoever's "frame of reference" we are viewing the game from
        // EventHandler::progressTime();
    }
    endwin();  // end ncurses
}

#endif