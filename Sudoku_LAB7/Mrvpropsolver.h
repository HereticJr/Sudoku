#pragma once

#include "Solver.h"
#include <optional>

// Solves the board using backtracking with MRV heuristic and forced-move propagation
class MRVPropSolver : public Solver
{
public:
    std::optional<Board> Solve(const Board& board) override;

private:
    std::optional<Board> SolveImpl(const Board& board);
};
