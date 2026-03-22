#include <iostream>
#include "sudoku.h"

int main() {
    int board[GRID_SIZE][GRID_SIZE];

    // Вызываем функции реализации
    readBoard(board);

    std::cout << "\nYour Sudoku Board:\n";
    printBoard(board);

    if (isBoardValid(board)) {
        std::cout << "\nResult: The board is VALID.\n";
    }
    else {
        std::cout << "\nResult: The board is INVALID.\n";
    }

    return 0;
}