#ifndef INPUT_HANDLER_CPP
#define INPUT_HANDLER_CPP

#include "InputHandler.h"

// Called by the main game loop. True means 'quit game'.
inline bool InputHandler::recieveInput(int input) {
    if (input == 'q') {
        return true;
    }
    return false;
}

#endif