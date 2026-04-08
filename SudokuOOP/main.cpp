#include <iostream>
#include "Board.h"

int main() {
    Board board;

    board.read();
    board.print();

    if (board.validate()) {
        std::cout << "Board is valid.\n";
    }
    else {
        std::cout << "Board is invalid.\n";
    }

    return 0;
}