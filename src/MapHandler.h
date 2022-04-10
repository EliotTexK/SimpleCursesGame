#ifndef MAP_HANDLER_H
#define MAP_HANDLER_H

#include "GameObject.h"
using namespace constants;

struct GameObject;

// Static accessible.
class MapHandler {
    static GameObject *gameMap[LEVEL_SIZE_X][LEVEL_SIZE_Y];
    static unsigned int currentTime;

   public:
    static void initMap();
    static void addMapPosition(GameObject *gameObject);
    static void updateMapPosition(GameObject *gameObject, int xPrev, int yPrev);
    static GameObject *getObjectAtPos(int x, int y);
};

#endif