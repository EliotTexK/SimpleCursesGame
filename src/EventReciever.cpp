#ifndef EVENT_RECIEVER_CPP
#define EVENT_RECIEVER_CPP

#include "Event.cpp"
#include "constants.h"
using namespace constants;

struct EventReciever
{
  ~EventReciever() {};
  virtual void recieveEvent(Event *ev) {};
};

#endif