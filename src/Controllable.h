#ifndef CONTROLLABLE_H
#define CONTROLLABLE_H

#include "GameObject.h"
#include "EventHandler.h"
#include "events.h"

struct Controllable : GameObject {
    Controllable();
    Controllable(int _x, int _y);
    void recieveInput(int input);
    void recieveEvent(Event* ev);
};

#endif