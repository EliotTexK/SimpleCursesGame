#ifndef EVENT_HANDLER_CPP
#define EVENT_HANDLER_CPP

#include "EventHandler.h"
using namespace constants;

inline EventHandler::EventHandler()
{
    // initialize array of events
    for (int i = 0; i < MAX_EVENTS; i++) {
        eventTimeline[i] = nullptr;
    }
}

// probably call this from the "player", or whatever instance is
// "observing" the game world
inline void EventHandler::progressTime()
{
    currentTime ++;
    for (int i = 0; i < MAX_EVENTS; i++)
    {
        Event* ev = eventTimeline[i];
        if (ev == nullptr) continue;

        if (ev->globalTime < currentTime)
        {
            delete ev;
            eventTimeline[i] = nullptr;
        }
        if (ev->globalTime == currentTime)
        {
            ev->target->recieveEvent(ev);
            delete ev;
            eventTimeline[i] = nullptr;
        }
    }
}

// TODO: sort the event timeline by globalTime. This way,
// it's easier to know where to put new events, and so that
// the game loop becomes far more efficient
inline void EventHandler::addEvent(Event *ev)
{
    ev->globalTime = currentTime + ev->time;
    for (int i = 0; i < MAX_EVENTS; i++) {
        if (eventTimeline[i] == nullptr) {
            eventTimeline[i] = ev;
            break;
        }
    }
}

#endif