//
// Created by Romane on 10/01/2022.
//

#include "cell.h"
#include <cstdlib>
#include <iostream>

Cell::Cell(int row, int column) {
    this->row = row;
    this->column = column;
    visited = false;
    content = 'x';
}

void Cell::setVisited(bool b) { visited = b; }

bool Cell::isVisited() const { return visited; }

int Cell::getRow() const { return row; }

int Cell::getColumn() const { return column; }

char Cell::getContent() const { return content; }

void Cell::print() const {
    std::cout << "row : " << row << " | ";
    std::cout << "column : " << column << std::endl;
}

void Cell::setEmpty() {

}
