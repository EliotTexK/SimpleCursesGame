#ifndef EVENT_RECIEVER_CPP
#define EVENT_RECIEVER_CPP

#include "Event.h"
#include "constants.h"
using namespace constants;

struct EventReciever
{
  // so that we don't just delete an event-recieving object
  // that still has pending events on the timeline
  char pendingEvents = 0;

  // if the object is to be deleted (handled by EventHandler)
  bool toDelete = false;
  virtual void recieveEvent(Event *ev) {};

  // calling the destructor of an EventReciever also calls the
  // destructor of any derived class
  virtual ~EventReciever() {};
};

#endif