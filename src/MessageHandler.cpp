#ifndef MESSAGE_HANDLER_CPP
#define MESSAGE_HANDLER_CPP

#include "MessageHandler.h"
using namespace constants;

MessageHandler::MessageHandler() {
    messageWindow = newwin(6, LEVEL_SIZE_X, LEVEL_SIZE_Y, 0);
    scrollok(messageWindow, true); // allows terminal-style scrolling text
}

void MessageHandler::print(std::string message) {
    wprintw(messageWindow, message.c_str());
    wrefresh(messageWindow);
}

void MessageHandler::print() {
    wrefresh(messageWindow);
}

#endif