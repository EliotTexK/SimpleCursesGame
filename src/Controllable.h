#ifndef CONTROLLABLE_H
#define CONTROLLABLE_H

#include "MapObject.h"
#include "EventHandler.h"
#include "events.h"

struct Controllable : MapObject {
    Controllable();
    Controllable(int _x, int _y);
    void recieveInput(int input);
    void procEvent(Event* ev);
};

#endif