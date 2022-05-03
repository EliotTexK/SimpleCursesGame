#ifndef INPUT_HANDLER_CPP
#define INPUT_HANDLER_CPP

#include "InputHandler.h"

inline Controllable* InputHandler::control;

// Make sure that when you call this, _control has been instantiated
inline void InputHandler::init(Controllable* _control) { control = _control; }

// Called by the main game loop. True means 'quit game'.
inline bool InputHandler::recieveInput() {
    RenderHandler::renderMap(control->x, control->y);
    RenderHandler::highlight(control->x, control->y, control->display);
    int input = getch();
    switch (input) {
        case 'q':
            // quit game
            return true;
            break;
        case KEY_UP:
            control->recieveInput(InputIDs::moveUp);
            break;
        case KEY_DOWN:
            control->recieveInput(InputIDs::moveDown);
            break;
        case KEY_LEFT:
            control->recieveInput(InputIDs::moveLeft);
            break;
        case KEY_RIGHT:
            control->recieveInput(InputIDs::moveRight);
            break;
        case 'm':
            char choice = createMenu(std::vector<std::string>{
                "option0", "option1", "option2", "option3", "destroy everything"});
            if (choice == 4) {
                for (int x = 0; x < LEVEL_SIZE_X; x++) {
                    for (int y = 0; y < LEVEL_SIZE_Y; y++) {
                        MapObject *obj = MapHandler::getObjectAtPos(x,y);
                        if (obj != nullptr && obj != control) {
                            obj->decrementConnections();
                        }
                    }
                }
                // test to see if pending events are discarded
                //EventHandler::progressTime(10);
            }
            break;
    }

    return false;
}

// takes an ordered list of menu options and creates a menu
// returns the index of the selected option, or -1 for no option
inline char InputHandler::createMenu(std::vector<std::string> options) {
    char output = 0;
    char select = 0;
    unsigned char len = options.size();
    WINDOW* menuWindow = newwin(len, 20, 0, LEVEL_SIZE_X);
    keypad(menuWindow,true); // you have to specify this or arrow keys will not work

    // loop until a selection is made, or quit out
    bool madeSelection = false;
    while (!madeSelection) {
        // print the menu
        werase(menuWindow);
        for (char i = 0; i < len; i++) {
            std::string option = options.at(i);
            if (i == select) {
                wattron(menuWindow, A_REVERSE);
            }
            wprintw(menuWindow, option.c_str());
            wprintw(menuWindow, "\n");
            wattroff(menuWindow, A_REVERSE);
        }
        wrefresh(menuWindow);
        // get inputs for scrolling up/down, or selecting an option
        wrefresh(menuWindow);
        switch (getch()) {
            case KEY_UP:
                if (select > 0) select--;
                break;
            case KEY_DOWN:
                if (select < len - 1) select++;
                break;
            case KEY_ENTER:
            case 10:    // 10 = ASCII return, as opposed to KEY_ENTER, which is on the keypad
                output = select;
                madeSelection = true;
                break;
            case 27:    // 27 = ASCII ESC
            case 'q':
                output = -1;
                madeSelection = true;
                break;
        }
    }
    // we're done, delete the window
    werase(menuWindow);
    wrefresh(menuWindow);
    delwin(menuWindow);

    return output;
}

#endif