#ifndef MAP_HANDLER_CPP
#define MAP_HANDLER_CPP

#include "MapHandler.h"
using namespace constants;

std::vector<MapObject *> MapHandler::gameObjects;
MapObject* MapHandler::gameMap[LEVEL_SIZE_X][LEVEL_SIZE_Y];
unsigned int MapHandler::currentTime = 0;
static int highlightX = -1;
static int highlightY = -1;

void MapHandler::initMap() {
    // initialize array of map locations
    for (int x = 0; x < LEVEL_SIZE_X; x++) {
        for (int y = 0; y < LEVEL_SIZE_Y; y++) {
            gameMap[x][y] = nullptr;
        }
    }
}

void MapHandler::addNewMapObject(MapObject *gameObject) {
    gameObjects.push_back(gameObject);
    addMapPosition(gameObject);
}

void MapHandler::addMapPosition(MapObject *gameObject) {
    gameMap[gameObject->x][gameObject->y] = gameObject;
}

void MapHandler::updateMapPosition(MapObject *gameObject, int xPrev,
                                          int yPrev) {
    // GameObject should check for OOB itself when moving
    // Yeah, we might have issues if there's multiple objects in the same space,
    // but let's resolve that later once we actually know what we want to do.
    gameMap[xPrev][yPrev] = nullptr;
    addMapPosition(gameObject);
}

MapObject *MapHandler::getObjectAtPos(int x, int y) {
    // check for out-of-bounds
    if (checkForOOB(x, y)) {
        return nullptr;
    } else {
        return gameMap[x][y];
    }
}

#endif