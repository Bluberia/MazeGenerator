//
// Created by roman on 10/01/2022.
//

#include <cstdlib>
#include <iostream>
#include "grid.h"
#include "cell.h"

using namespace std;

Grid::Grid(int width, int height) {
    this->width = width;
    this->height = height;
    createCells();
    current = &cells[0];
}

void Grid::createCells() {
    for (int row = 0; row < this->height; row++) {
        for (int column = 0; column < this->width; column++) {
            this->cells.emplace_back(row, column);
        }
    }
}

void Grid::generateMaze() {
    while (true) {
        current->setVisited(true);
        Cell *next = findNextCell();

        if (next != nullptr) {
            next->setVisited(true);
            backtrace.push(current);
            current->setEmpty();
            current = next;
        } else if (!backtrace.empty()) {
            current = backtrace.top();
            backtrace.pop();
        } else if (backtrace.empty()) {
            break;
        }
    }
    render();
}

void Grid::render() {
    for (Cell c: this->cells) {
        if (c.getColumn() == 0 && c.getRow() != 0)
            cout << "\n";
        cout << c.getContent();
    }
}

Cell *Grid::findNextCell() {
    std::vector<Cell *> availableNeighbors = getAvailableNeighbors();
    if (!availableNeighbors.empty()) {
        return availableNeighbors.at(rand() % availableNeighbors.size());
    }
    return nullptr;
}

std::vector<Cell *> Grid::getAvailableNeighbors() {
    std::vector<Cell *> neighbors;

    int currentRow = current->getRow();
    int currentColumn = current->getColumn();

    int neighborIndexes[4] = {
            calculateIndex(currentRow - 1, currentColumn),
            calculateIndex(currentRow, currentColumn + 1),
            calculateIndex(currentRow + 1, currentColumn),
            calculateIndex(currentRow, currentColumn - 1),
    };

    for (int i: neighborIndexes) {
        if (i != -1 && !cells[i].isVisited()) {
            neighbors.push_back(&cells[i]);
        }
    }

    return neighbors;
}

int Grid::calculateIndex(int row, int column) const {
    if (row < 0 || column < 0 || column > width - 1 || row > height - 1)
        return -1;
    else
        return column + row * width;
}