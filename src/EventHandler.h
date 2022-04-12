#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include "Event.h"
#include "MapObject.h"
using namespace constants;

// A singleton. All objects that import EventHandler
// have access to a timeLine to "post" events that will
// occur after a certain amount of time.
class EventHandler {
    static unsigned int currentTime;
    static Event *eventTimeline[MAX_EVENTS];

   public:
    static void initEventTimeline();
    static void progressTime(char time);
    static void addEvent(Event *ev);
};

#endif