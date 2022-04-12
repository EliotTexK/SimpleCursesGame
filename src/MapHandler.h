#ifndef MAP_HANDLER_H
#define MAP_HANDLER_H

#include "MapObject.h"
using namespace constants;

class MapObject;

// Static accessible.
class MapHandler {
    static MapObject *gameMap[LEVEL_SIZE_X][LEVEL_SIZE_Y];
    static unsigned int currentTime;

   public:
    static void initMap();
    static void addMapPosition(MapObject *gameObject);
    static void updateMapPosition(MapObject *gameObject, int xPrev, int yPrev);
    static MapObject *getObjectAtPos(int x, int y);
};

#endif