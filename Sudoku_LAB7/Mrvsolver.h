#pragma once

#include "Solver.h"
#include <optional>

// Solves the board using backtracking with MRV heuristic — selects the cell with fewest candidates
class MRVSolver : public Solver
{
public:
    std::optional<Board> Solve(const Board& board) override;

private:
    std::optional<Board> SolveImpl(const Board& board);
};
