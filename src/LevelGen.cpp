#ifndef LEVEL_GEN_CPP
#define LEVEL_GEN_CPP
#include <stdlib.h>

#include <vector>

// ratio: ratio of true to false spaces
static std::vector<std::vector<bool>> marchingSquares(int sizeX, int sizeY,
                                                      char ratio,
                                                      char iterations) {
    std::vector<std::vector<bool>> output =
        std::vector<std::vector<bool>>(sizeX, std::vector<bool>(sizeY));
    for (int x = 0; x < sizeX; x++) {
        for (int y = 0; y < sizeY; y++) {
            if (x == 0 || x == sizeX-1 || y == 0 || y == sizeY-1) {
                output.at(x).at(y) = true;
            } else {
                output.at(x).at(y) = !(rand() % ratio);
            }
        }
    }
    for (char i = 0; i < iterations; i++) {
        for (int x = 1; x < sizeX - 1; x++) {
            for (int y = 1; y < sizeY - 1; y++) {
                char wallCount = 0;
                for (int xNeighbor = x - 1; xNeighbor <= x + 1; xNeighbor++) {
                    for (int yNeighbor = y - 1; yNeighbor <= y + 1; yNeighbor++) {
                        if (output.at(xNeighbor).at(yNeighbor)) {
                            if (!(xNeighbor == x && yNeighbor == y)) {
                                wallCount++;
                            }
                        }
                    }
                }
                if (wallCount > 4) {
                    output.at(x).at(y) = true;
                } else if (wallCount < 4) {
                    output.at(x).at(y) = false;
                }
            }
        }
    }
    return output;
}

#endif