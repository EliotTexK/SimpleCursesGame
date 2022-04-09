#ifndef WALKER_CPP
#define WALKER_CPP

#include <string>
#include "Event.cpp"
#include "GameObject.cpp"
#include "events.h"

struct Walker : GameObject {
    void recieveEvent(Event *ev) {
        if (ev->eventID == EventIDs::wander) {
            char dir = rand() % 8;
            moveDir(dir);
            sendNewWanderEvent();
        }
    }
    Walker(int _x, int _y, MapHandler* _mapHandler, EventHandler* _eventHandler)
        : GameObject(_x, _y, 'W', _mapHandler, _eventHandler) {
        sendNewWanderEvent();
    }
    void sendNewWanderEvent() {
        Event* ev = new Event();
        ev->eventID = EventIDs::wander;
        ev->target = this;
        ev->time = (rand() % 2) + 1;
        eventHandler->addEvent(ev);
    }
};

#endif