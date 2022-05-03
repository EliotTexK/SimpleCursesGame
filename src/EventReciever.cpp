#ifndef EVENT_RECIEVER_CPP
#define EVENT_RECIEVER_CPP

#include "Event.h"
#include "constants.h"
using namespace constants;

struct EventReciever
{
  ~EventReciever() {};
  // so that we don't just delete an event-recieving object
  // that still has pending events on the timeline
  char pendingEvents = 0;
  virtual void recieveEvent(Event *ev) {};
};

#endif