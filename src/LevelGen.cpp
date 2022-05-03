#ifndef LEVEL_GEN_CPP
#define LEVEL_GEN_CPP
#include <stdlib.h>

#include "constants.h"
using namespace constants;

struct LevelGen {
    bool level[LEVEL_SIZE_X][LEVEL_SIZE_Y];
    void marchingSquares(char ratio, char iterations) {
        // fill border
        for (int x = 0; x < LEVEL_SIZE_X; x++) {
            for (int y = 0; y < LEVEL_SIZE_Y; y++) {
                if (x == 0 || x == LEVEL_SIZE_X - 1 || y == 0 || y == LEVEL_SIZE_Y - 1) {
                    level[x][y] = true;
                } else {
                    level[x][y] = !(rand() % ratio);
                }
            }
        }
        for (char i = 0; i < iterations; i++) {
            for (int x = 1; x < LEVEL_SIZE_X - 1; x++) {
                for (int y = 1; y < LEVEL_SIZE_Y - 1; y++) {
                    char wallCount = 0;
                    for (int xNeighbor = x - 1; xNeighbor <= x + 1;
                         xNeighbor++) {
                        for (int yNeighbor = y - 1; yNeighbor <= y + 1;
                             yNeighbor++) {
                            if (level[xNeighbor][yNeighbor]) {
                                if (!(xNeighbor == x && yNeighbor == y)) {
                                    wallCount++;
                                }
                            }
                        }
                    }
                    if (wallCount > 4) {
                        level[x][y] = true;
                    } else if (wallCount < 4) {
                        level[x][y] = false;
                    }
                }
            }
        }
    }
};

#endif