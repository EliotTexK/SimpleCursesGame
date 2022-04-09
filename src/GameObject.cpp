#ifndef GAME_OBJECT_CPP
#define GAME_OBJECT_CPP

#include "GameObject.h"

#include "EventHandler.h"
#include "MapHandler.h"
#include "constants.h"
using namespace constants;

inline GameObject::GameObject(int _x, int _y, char _display,
                              MapHandler *_mapHandler,
                              EventHandler *_eventHandler) {
    x = _x;
    y = _y;
    display = _display;
    mapHandler = _mapHandler;
    eventHandler = _eventHandler;
}

inline void GameObject::moveTo(int _x, int _y) {
    if (checkForOOB(_x, _y)) {
        return;
    }
    int xPrev = x;
    int yPrev = y;
    x = _x;
    y = _y;
    mapHandler->updateMapPosition(this, xPrev, yPrev);
}

inline void GameObject::moveDir(char dir) {
    if (dir > 7) {
        return;
    }
    char to_x = 0;
    char to_y = 0;
    // starts with --->, circles clockwise
    switch (dir) {
        case Directions::right:
            to_x = 1;
            break;
        case Directions::right_down:
            to_x = 1;
            to_y = 1;
            break;
        case Directions::down:
            to_y = 1;
            break;
        case Directions::left_down:
            to_y = 1;
            to_x = -1;
            break;
        case Directions::left:
            to_x = -1;
            break;
        case Directions::left_up:
            to_x = -1;
            to_y = -1;
            break;
        case Directions::up:
            to_y = -1;
            break;
        case Directions::right_up:
            to_y = -1;
            to_x = 1;
            break;
    }
    moveTo(x + to_x, y + to_y);
}

#endif