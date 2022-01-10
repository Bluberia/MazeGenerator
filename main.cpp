#include <iostream>
#include <string>
#include <stdexcept>
#include "grid.h"

using namespace std;

bool tryParse(std::string &input, int &output) {
    try {
        output = std::stoi(input);
    } catch (invalid_argument) {
        return false;
    }
    return true;
}

void getInfo(int *width, int *height) {
    std::string input;

    cout << "Enter width:";
    getline(std::cin, input);
    while (!tryParse(input, *width)) {
        std::cout << "Bad entry. Enter a NUMBER:";
        getline(std::cin, input);
    }

    cout << "Enter height:";
    getline(std::cin, input);
    while (!tryParse(input, *height)) {
        std::cout << "Bad entry. Enter a NUMBER:";
        getline(std::cin, input);
    }
}

int main() {
    int width;
    int height;

    getInfo(&width, &height);
    Grid grid = Grid(width, height);
    grid.generateMaze();

    return 0;
}