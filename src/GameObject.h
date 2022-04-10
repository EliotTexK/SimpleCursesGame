#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Event.h"
#include "EventReciever.cpp"
#include "EventHandler.h"
#include "MapHandler.h"
#include "constants.h"

#include <string>

class MapHandler;
class EventHandler;

struct GameObject : EventReciever {
    int x, y;
    char display;
    std::string getDescription();
    GameObject(int _x, int _y, char _display);
    void moveTo(int _x, int _y);
    void moveDir(char dir);
};

#endif