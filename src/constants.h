#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace constants {

// level-generation constants
constexpr unsigned int LEVEL_SIZE_X = 60;
constexpr unsigned int LEVEL_SIZE_Y = 30;
constexpr unsigned int SCREEN_SIZE_X = 60;
constexpr unsigned int SCREEN_SIZE_Y = 30;
constexpr unsigned int MAX_SPACE = 5;
constexpr unsigned int MAX_EVENTS = 200;

inline bool checkForOOB(int x, int y) {
    return (x >= LEVEL_SIZE_X || x < 0 || y >= LEVEL_SIZE_Y || y < 0);
}

enum Directions {
    right,
    right_down,
    down,
    left_down,
    left,
    left_up,
    up,
    right_up
};

enum Colors {
    red,
    orange,
    yellow,
    green,
    blue,
    indigo,
    violet,
    brown,
    black,
    white
};

}  // namespace constants
#endif