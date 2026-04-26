#pragma once

#include "Solver.h"
#include <optional>

// Solves the board using functional recursive backtracking (no mutation of input)
class BacktrackingSolver : public Solver
{
public:
    std::optional<Board> Solve(const Board& board) override;
};