#include "Solver.h"

// Solve the board using recursive backtracking
bool Solver::solve(Board& board) {
    int row, col;

    if (!findEmptyCell(board, row, col)) {
        return true;
    }

    for (int value = 1; value <= Board::SIZE; ++value) {
        if (board.isValidPlacement(row, col, value)) {
            board.setCell(row, col, value);

            if (solve(board)) {
                return true;
            }

            board.setCell(row, col, 0);
        }
    }

    return false;
}

// Scan the board row by row to find the first empty cell (value == 0)
bool Solver::findEmptyCell(const Board& board, int& row, int& col) const {
    for (row = 0; row < Board::SIZE; ++row) {
        for (col = 0; col < Board::SIZE; ++col) {
            if (board.getCell(row, col) == 0) {
                return true;
            }
        }
    }
    return false;
}