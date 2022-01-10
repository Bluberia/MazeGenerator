//
// Created by roman on 10/01/2022.
//

#ifndef MAZEGENERATOR_GRID_H
#define MAZEGENERATOR_GRID_H

#include <stack>
#include <vector>
#include "cell.h"

class Grid {
private:
    int width;
    int height;

    std::vector<Cell> cells;
    std::stack<Cell *> backtrace;
    Cell *current;

    void createCells();
    int calculateIndex(int i, int j) const;
    std::vector<Cell *> getAvailableNeighbors();
    Cell *findNextCell();
    void render();

public:
    Grid(int width, int height);
    void generateMaze();
};

#endif //MAZEGENERATOR_GRID_H
