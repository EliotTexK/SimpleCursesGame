#ifndef MESSAGE_HANDLER_CPP
#define MESSAGE_HANDLER_CPP

#include "MessageHandler.h"
using namespace constants;

// inline can solve the issue of "compiler finds multiple
// declarations of this static member/function"
inline WINDOW* MessageHandler::messageWindow = NULL;

// Make sure to call this AFTER you start ncurses
void MessageHandler::init() {
    messageWindow = newwin(6, LEVEL_SIZE_X, LEVEL_SIZE_Y, 0);
    scrollok(messageWindow, true);  // enables terminal-esque scrolling text
}

void MessageHandler::print(std::string message) {
    wprintw(messageWindow, message.c_str());
    wprintw(messageWindow, "\n");
    wrefresh(messageWindow);
}

#endif