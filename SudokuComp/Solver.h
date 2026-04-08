#pragma once

#include "Board.h"

// Class responsible for solving a Sudoku puzzle using backtracking
class Solver {
public:
    bool solve(Board& board);

private:
    bool findEmptyCell(const Board& board, int& row, int& col) const;
};