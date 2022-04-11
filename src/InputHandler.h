#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "Controllable.h"
#include <ncurses.h>

class InputHandler {
    static Controllable * control;
    public:
    static void init(Controllable * _control);
    static bool recieveInput();
};

#endif