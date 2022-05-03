#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Event.h"
#include "ContainerObject.cpp"
#include "EventHandler.h"
#include "MapHandler.h"
#include "constants.h"

#include <string>

class MapHandler;
class EventHandler;

/* This is a generic class that can be used to populate
// tiles on the map. Or, you can inherit from it to create
// something more complex that also can populate map tiles.
*/
struct MapObject : public ContainerObject {
    int x, y;
    char display;
    virtual std::string getDescription();
    MapObject(int _x, int _y, char _display);
    // override this if you want collision
    void moveTo(int _x, int _y);
    void moveDir(char dir);
};

#endif