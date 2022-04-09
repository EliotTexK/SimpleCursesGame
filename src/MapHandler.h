#ifndef MAP_HANDLER_H
#define MAP_HANDLER_H

#include "Event.cpp"
#include "GameObject.h"
using namespace constants;

// Provides some useful encapsulation. GameObjects will
// have access to a single instance of MapHandler. They can find
// other objects based on position, and they can update their own.
// They can also add events to the timeline to occur after a certain
// amount of time.
class MapHandler {
    private:
    GameObject *gameMap[LEVEL_SIZE_X][LEVEL_SIZE_Y];
    unsigned int currentTime = 0;
    Event *eventTimeline[MAX_EVENTS];
    public:
    MapHandler();
    void updateMapPosition(GameObject * gameObject, int xPrev, int yPrev);
    GameObject* getObjectAtPos(int x, int y);
};

#endif