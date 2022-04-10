#ifndef MESSAGE_HANDLER_H
#define MESSAGE_HANDLER_H

#include <curses.h>
#include <string>
#include "constants.h"
using namespace constants;

class MessageHandler {
    static WINDOW* messageWindow;

   public:
    static void init();
    static void print(std::string message);
};

#endif