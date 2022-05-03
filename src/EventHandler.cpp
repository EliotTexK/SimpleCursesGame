#ifndef EVENT_HANDLER_CPP
#define EVENT_HANDLER_CPP

#include "EventHandler.h"
using namespace constants;

unsigned int EventHandler::currentTime = 0;
Event* EventHandler::eventTimeline[MAX_EVENTS];

void EventHandler::initEventTimeline() {
    for (int i = 0; i < MAX_EVENTS; i++) {
        eventTimeline[i] = nullptr;
    }
}

// probably call this from the "player", or whatever instance is
// "observing" the game world
void EventHandler::progressTime(char time) {
    for (char i = 0; i < time; i++) {
        currentTime++;
        for (int i = 0; i < MAX_EVENTS; i++) {
            Event* ev = eventTimeline[i];
            if (ev == nullptr) continue;

            if (ev->globalTime < currentTime) {
                delete ev;
                eventTimeline[i] = nullptr;
            }
            if (ev->globalTime == currentTime) {
                ev->target->recieveEvent(ev);
                // pending events decrement when events are recieved
                ev->target->pendingEvents--;
                delete ev;
                eventTimeline[i] = nullptr;
            }
        }
    }
}

// TODO: sort the event timeline by globalTime. This way,
// it's easier to know where to put new events, and so that
// the game loop becomes far more efficient
void EventHandler::addEvent(Event* ev) {
    // increment pending events for the eventReciever in question,
    // so that we can know whether or not we can safely delete it
    ev->target->pendingEvents++;
    ev->globalTime = currentTime + ev->localTime;
    for (int i = 0; i < MAX_EVENTS; i++) {
        if (eventTimeline[i] == nullptr) {
            eventTimeline[i] = ev;
            break;
        }
    }
}

#endif