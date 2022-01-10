#include <iostream>
#include <string>
#include <stdexcept>

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

void displayMaze(int width, int height) {
    for (int column = 0; column < width + 2; ++column) {
        cout << "#";
    }
    cout << "\n";

    for (int row = 0; row < height; ++row) {
        cout << "#";
        for (int column = 0; column < width; ++column) {
            cout << ".";
        }
        cout << "#\n";
    }

    for (int column = 0; column < width + 2; ++column) {
        cout << "#";
    }
    cout << "\n";
}

int main() {
    int width;
    int height;

    getInfo(&width, &height);
    displayMaze(width, height);

    return 0;
}