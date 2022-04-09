#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include "Event.cpp"
#include "GameObject.h"
using namespace constants;

// Provides some useful encapsulation. GameObjects will
// have access to a single instance of MapHandler. They can find
// other objects based on position, and they can update their own.
// They can also add events to the timeline to occur after a certain
// amount of time.
class EventHandler {
    private:
    unsigned int currentTime = 0;
    Event *eventTimeline[MAX_EVENTS];
    public:
    EventHandler();
    void progressTime();
    void addEvent(Event * ev);
};

#endif