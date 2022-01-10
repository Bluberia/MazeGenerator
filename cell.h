//
// Created by Romane on 10/01/2022.
//

#ifndef MAZEGENERATOR_CELL_H
#define MAZEGENERATOR_CELL_H

class Cell {
private:
    int row, column;
    char content;
    bool visited;
    enum direction {
        TOP, RIGHT, BOTTOM, LEFT
    };

public:
    Cell(int i, int j);

    void print() const;
    void setEmpty();
    char getContent() const;
    void setVisited(bool);
    bool isVisited() const;
    int getRow() const;
    int getColumn() const;
};


#endif //MAZEGENERATOR_CELL_H
