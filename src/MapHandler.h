#ifndef MAP_HANDLER_H
#define MAP_HANDLER_H

#include "MapObject.h"
#include "LevelGen.cpp"
using namespace constants;

class MapObject;

// Static accessible.
class MapHandler {
    static std::vector<MapObject *> gameObjects;
    static MapObject *gameMap[LEVEL_SIZE_X][LEVEL_SIZE_Y];
    static unsigned int currentTime;

   public:
    static void initMap();
    static void addNewMapObject(MapObject *gameObject);
    static void addMapPosition(MapObject *gameObject);
    static void updateMapPosition(MapObject *gameObject, int xPrev, int yPrev);
    static MapObject *getObjectAtPos(int x, int y);
};

#endif