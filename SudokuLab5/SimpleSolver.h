#pragma once

#include "Solver.h"
#include <optional>

// Solves the board by iteratively applying naked singles (cells with one valid candidate)
class SimpleSolver : public Solver
{
public:
    std::optional<Board> Solve(const Board& board) override;

private:
    // Returns a board with one naked single filled, or nullopt if none found
    std::optional<Board> applyNakedSingle(const Board& board) const;
};