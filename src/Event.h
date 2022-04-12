#ifndef EVENT_H
#define EVENT_H

// forward declare
class EventReciever;

struct Event {
    unsigned int eventID;  // necessary for identifying the event

    unsigned char localTime;       // so that events can occur chronologically
                              // this represents the amount of time an event
                              // takes to occur
    // REMEMBER, if you decide to get rid of globalTime (just have 1 time variable)
    // you will need to fix the way the player's POV works, advancing time based
    // on this local time attribute
    unsigned int globalTime;  // represents when the event is set to occur
    EventReciever *target;
    EventReciever *source;
    char data1, data2, data3;  // event data
};

#endif