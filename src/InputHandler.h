#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "Controllable.h"
#include "MapHandler.h"
#include "RenderHandler.h"
#include <vector>
#include <ncurses.h>
#include "constants.h"

class InputHandler {
    static Controllable * control;
    static std::vector<MapObject *> gameObjects;
    public:
    static void init(Controllable * _control);
    static bool recieveInput();
};

#endif