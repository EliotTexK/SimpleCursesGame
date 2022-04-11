#ifndef INPUT_HANDLER_CPP
#define INPUT_HANDLER_CPP

#include "InputHandler.h"

inline Controllable* InputHandler::control;

inline void InputHandler::init(Controllable * _control) {
    control = _control;
}

// Called by the main game loop. True means 'quit game'.
inline bool InputHandler::recieveInput() {
    int input = getch();
    switch (input) {
        case 'q':
            // quit game
            return true;
            break;
        case 'w':
            control->recieveInput(InputIDs::moveUp);
            break;
        case 's':
            control->recieveInput(InputIDs::moveDown);
            break;
        case 'a':
            control->recieveInput(InputIDs::moveLeft);
            break;
        case 'd':
            control->recieveInput(InputIDs::moveRight);
            break;
    }

    return false;
}

#endif