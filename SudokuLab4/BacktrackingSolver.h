#pragma once

#include "Solver.h"

// Solves the board using recursive backtracking
class BacktrackingSolver : public Solver
{
public:
    bool Solve(Board& board) override;

private:
    bool findEmptyCell(const Board& board, int& row, int& col) const;
};