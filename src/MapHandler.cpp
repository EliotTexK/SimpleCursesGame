#ifndef MAP_HANDLER_CPP
#define MAP_HANDLER_CPP

#include "MapHandler.h"
using namespace constants;

inline MapHandler::MapHandler() {
    // initialize array of map locations
    for (int x = 0; x < LEVEL_SIZE_X; x++) {
        for (int y = 0; y < LEVEL_SIZE_Y; y++) {
            gameMap[x][y] = nullptr;
        }
    }
    // initialize array of events
    for (int i = 0; i < MAX_EVENTS; i++) {
        eventTimeline[i] = nullptr;
    }
}

inline void MapHandler::addMapPosition(GameObject *gameObject) {
    gameMap[gameObject->x][gameObject->y] = gameObject;
}

inline void MapHandler::updateMapPosition(GameObject *gameObject, int xPrev,
                                          int yPrev) {
    // GameObject should check for OOB itself when moving
    // Yeah, we might have issues if there's multiple objects in the same space,
    // but let's resolve that later once we actually know what we want to do.
    gameMap[xPrev][yPrev] = nullptr;
    addMapPosition(gameObject);
}

inline GameObject *MapHandler::getObjectAtPos(int x, int y) {
    // check for out-of-bounds
    if (checkForOOB(x, y)) {
        return nullptr;
    } else {
        return gameMap[x][y];
    }
}

#endif