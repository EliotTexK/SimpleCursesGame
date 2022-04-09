#ifndef MAIN_H
#define MAIN_H

#include <ncurses.h>
#include <vector>
#include "constants.h"
#include "GameObject.h"
#include "MapHandler.cpp"
#include "EventHandler.cpp"
#include "Walker.cpp"

std::vector<GameObject*> gameObjects;
MapHandler mapHandler;
EventHandler eventHandler;

void render();
int main();

#endif