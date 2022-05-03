#ifndef COMPONENT_CPP
#define COMPONENT_CPP

#include "EventReciever.cpp"

/* This is an EventReciever with one caveat: it counts the
// number of refrences to it, and deletes itself if there
// are none. This is important, because these can be attached
// to multiple GameObjects. We don't want to just immediately
// delete them when a GameObject is deleted, because they may
// still be used by others. Essentially, we need to prevent
// memory leaks and also references to freed memory.
*/
class Component : public EventReciever {
    char connections = 0;

   public:
    void incrementConnections() {
        connections++;
        if (connections <= 0) {
            // if no pending events exist, delete this
            // if pending events exist, wait to be deleted by EventHandler
            if (pendingEvents <= 0) {
                delete this;
            } else {
                toDelete = true;
            }
        }
    }
    // my implementation of a safe delete
    void decrementConnections() {
        connections--;
        if (connections <= 0) {
            // if no pending events exist, delete this
            // if pending events exist, wait to be deleted by EventHandler
            if (pendingEvents <= 0) {
                delete this;
            } else {
                toDelete = true;
            }
        }
    }
    virtual void recieveEvent(Event *ev) {};
    virtual ~Component() {};
};

#endif