#pragma once

#include "Solver.h"
#include <optional>

// Solves the board using functional recursive backtracking — selects the first empty cell
class BacktrackingSolver : public Solver
{
public:
    std::optional<Board> Solve(const Board& board) override;

private:
    std::optional<Board> SolveImpl(const Board& board);
};
