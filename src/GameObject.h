#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Event.cpp"
#include "EventReciever.cpp"

class MapHandler;
class EventHandler;

struct GameObject : EventReciever {
    int x, y;
    char display;
    MapHandler* mapHandler;
    EventHandler* eventHandler;
    std::string getDescription();
    GameObject(int _x, int _y, char _display, MapHandler* mapHandler,
               EventHandler* eventHandler);
    void moveTo(int _x, int _y);
    void moveDir(char dir);
};

#endif