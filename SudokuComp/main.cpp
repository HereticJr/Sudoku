#include <iostream>
#include "Board.h"
#include "Solver.h"

int main() {
    Board board;
    board.read();

    std::cout << "Initial board:\n";
    board.print();

    if (!board.validate()) {
        std::cout << "Board is invalid. Cannot solve.\n";
        return 1;
    }

    Solver solver;
    if (solver.solve(board)) {
        std::cout << "\nSolved board:\n";
        board.print();
    }
    else {
        std::cout << "\nNo solution exists.\n";
    }

    return 0;
}