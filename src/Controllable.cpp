#ifndef CONTROLLABLE_CPP
#define CONTROLLABLE_CPP

#include "Controllable.h"

Controllable::Controllable() : GameObject(0, 0, 'C') {}

Controllable::Controllable(int _x, int _y)
: GameObject(_x, _y, 'C') {
}

void Controllable::recieveInput(int input) {
    Event* ev = new Event();
    switch (input) {
        case InputIDs::moveLeft:
            ev->eventID = EventIDs::moveDirection;
            ev->data1   = Directions::left;
            ev->time    = 1;
            ev->target  = this;
            EventHandler::addEvent(ev);
            break;
        case InputIDs::moveRight:
            ev->eventID = EventIDs::moveDirection;
            ev->data1   = Directions::right;
            ev->time    = 1;
            ev->target  = this;
            EventHandler::addEvent(ev);
            break;
        case InputIDs::moveUp:
            ev->eventID = EventIDs::moveDirection;
            ev->data1   = Directions::up;
            ev->time    = 1;
            ev->target  = this;
            EventHandler::addEvent(ev);
            break;
        case InputIDs::moveDown:
            ev->eventID = EventIDs::moveDirection;
            ev->data1   = Directions::down;
            ev->time    = 1;
            ev->target  = this;
            EventHandler::addEvent(ev);
            break;
    }
}

void Controllable::recieveEvent(Event* ev) {
    // TODO:
    // later, we can add a more sophisticated entity-component
    // system so that we can reuse recieveEvent to its potential
    if (ev->eventID == EventIDs::moveDirection) {
        moveDir(ev->data1);
    }
}

#endif