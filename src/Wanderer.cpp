#ifndef WALKER_CPP
#define WALKER_CPP

#include <string>

#include "Event.h"
#include "MapObject.h"
#include "MessageHandler.h"
#include "events.h"

struct Wanderer : MapObject {

    void procEvent(Event* ev) {
        if (ev->eventID == EventIDs::wander) {
            char dir = rand() % 8;
            moveDir(dir);
            sendNewWanderEvent();
            produceRandomMessage();
        }
    }
    Wanderer(int _x, int _y) : MapObject(_x, _y, 'W') { sendNewWanderEvent(); }

   private:
    void sendNewWanderEvent() {
        Event* ev = new Event();
        ev->eventID = EventIDs::wander;
        ev->target = this;
        ev->localTime = (rand() % 3) + 2;
        EventHandler::addEvent(ev);
    }
    void produceRandomMessage() {
        switch (rand() % 3) {
            case 0:
                MessageHandler::print("Just wanderin' around...");
                break;
            case 1:
                MessageHandler::print("I'm bored...");
                break;
            case 2:
                MessageHandler::print(
                    "Don't really know where I'm goin'. But I'll end up "
                    "somewhere eventually...");
                break;
        }
    }
};

#endif