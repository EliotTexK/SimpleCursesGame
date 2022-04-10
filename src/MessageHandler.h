#ifndef MESSAGE_HANDLER_H
#define MESSAGE_HANDLER_H

#include <string>
#include <ncurses.h>
#include "constants.h"

WINDOW *messageWindow;

class MessageHandler {
    public:
    MessageHandler();
    void print(std::string message);
    void print();
};

#endif