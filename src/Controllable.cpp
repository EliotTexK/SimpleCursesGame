#ifndef CONTROLLABLE_CPP
#define CONTROLLABLE_CPP

#include "Controllable.h"

Controllable::Controllable() : MapObject(0, 0, 'C') {}

Controllable::Controllable(int _x, int _y)
: MapObject(_x, _y, 'C') {
}

void Controllable::recieveInput(int input) {
    Event* ev = new Event();
    switch (input) {
        case InputIDs::moveLeft:
            ev->eventID = EventIDs::moveDirection;
            ev->data1   = Directions::left;
            ev->localTime    = 2;
            ev->target  = this;
            EventHandler::addEvent(ev);
            break;
        case InputIDs::moveRight:
            ev->eventID = EventIDs::moveDirection;
            ev->data1   = Directions::right;
            ev->localTime    = 2;
            ev->target  = this;
            EventHandler::addEvent(ev);
            break;
        case InputIDs::moveUp:
            ev->eventID = EventIDs::moveDirection;
            ev->data1   = Directions::up;
            ev->localTime    = 2;
            ev->target  = this;
            EventHandler::addEvent(ev);
            break;
        case InputIDs::moveDown:
            ev->eventID = EventIDs::moveDirection;
            ev->data1   = Directions::down;
            ev->localTime    = 2;
            ev->target  = this;
            EventHandler::addEvent(ev);
            break;
    }
    EventHandler::progressTime(ev->localTime);
}

void Controllable::procEvent(Event* ev) {
    if (ev->eventID == EventIDs::moveDirection) {
        moveDir(ev->data1);
    }
}

#endif