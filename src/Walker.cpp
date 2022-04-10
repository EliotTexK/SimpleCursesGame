#ifndef WALKER_CPP
#define WALKER_CPP

#include <string>

#include "Event.h"
#include "GameObject.h"
#include "MessageHandler.h"
#include "events.h"

struct Walker : GameObject {
    void recieveEvent(Event* ev) {
        if (ev->eventID == EventIDs::wander) {
            char dir = rand() % 8;
            moveDir(dir);
            sendNewWanderEvent();
            produceRandomMessage();
        }
    }
    Walker(int _x, int _y)
        : GameObject(_x, _y, 'W') {
        sendNewWanderEvent();
    }

   private:
    void sendNewWanderEvent() {
        Event* ev = new Event();
        ev->eventID = EventIDs::wander;
        ev->target = this;
        ev->time = (rand() % 2) + 1;
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