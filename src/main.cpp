#ifndef MAIN_CPP
#define MAIN_CPP

#include "main.h"
using namespace constants;

Controllable player;

int main() {
    srand(time(NULL));  // seed prng

    initscr();              // start ncurses
    start_color();          // start color mode
    curs_set(0);            // don't display the cursor
    noecho();               // don't echo input characters to the terminal
    cbreak();               // don't buffer characters before carriage return
    keypad(stdscr,true);    // you must add this line or arrow keys won't work

    // MessageHandler and InputHandler must be initiated after ncurses
    MessageHandler::init();
    MapHandler::initMap();
    EventHandler::initEventTimeline();

    // add some random objects
    // TODO: refactor into some kind of level-generation
    for (int i = 0; i < 1; i++) {
        new Wanderer(rand() % LEVEL_SIZE_X, rand() % LEVEL_SIZE_Y);
    }

    // add the player
    player = Controllable(rand() % LEVEL_SIZE_X, rand() % LEVEL_SIZE_Y);

    // don't pass an object to InputHandler before you instantiate the object!
    InputHandler::init(&player);

    // game loop
    while (true) {
        RenderHandler::renderMap(player.x, player.y);
        // inputHandler can decide whether or not to quit the game
        if (InputHandler::recieveInput()) break;
        // Time progresses according to the "player", or whatever object's
        // "frame of reference" we are viewing the game from. The input handler
        // will have one such object, of type "Controllable". InputHandler will
        // call the Controllable instance's "recieveInput". Based on the designated
        // action, the Controllable will tell the EventHandler to progress time,
        // according to the amount of time it takes for its next action to occur
        // (represented as an event on the event timeline).
    }
    endwin();  // end ncurses
}

#endif