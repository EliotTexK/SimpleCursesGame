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

struct MapObject : public ContainerObject {
    int x, y;
    char display;
    std::string getDescription();
    MapObject(int _x, int _y, char _display);
    void moveTo(int _x, int _y);
    void moveDir(char dir);
};

#endif