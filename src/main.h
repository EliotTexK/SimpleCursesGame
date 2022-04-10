#ifndef MAIN_H
#define MAIN_H

#include <ncurses.h>
#include <vector>
#include "constants.h"
#include "GameObject.cpp"
#include "InputHandler.cpp"
#include "MapHandler.cpp"
#include "EventHandler.cpp"
#include "MessageHandler.cpp"
#include "Walker.cpp"

std::vector<GameObject*> gameObjects;
MapHandler mapHandler;
EventHandler eventHandler;
InputHandler inputHandler;
MessageHandler MessageHandler;


void render();
int main();

#endif