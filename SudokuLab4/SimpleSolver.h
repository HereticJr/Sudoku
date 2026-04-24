#pragma once

#include "Solver.h"

// Solves the board by repeatedly filling cells that have only one valid candidate (naked singles)
class SimpleSolver : public Solver
{
public:
    bool Solve(Board& board) override;

private:
    bool fillNakedSingles(Board& board) const;
    bool isSolved(const Board& board) const;
};