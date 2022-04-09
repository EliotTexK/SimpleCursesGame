#ifndef EVENT_CPP
#define EVENT_CPP

#include <vector>
#include <iostream>
#include "constants.h"

// forward declare
class EventReciever;

struct Event
{
    unsigned int eventID;       // necessary for identifying the event

    unsigned char time;         // so that events can occur chronologically
                                // this represents the amount of time an event
                                // takes to occur
    unsigned int globalTime;    // represents when the event is set to occur
    EventReciever *target;
    EventReciever *source;
    char data1, data2, data3;   // event data
};

#endif