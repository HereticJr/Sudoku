#pragma once

#include "Solver.h"
#include "Move.h"
#include <optional>
#include <vector>

// Solves the board by iteratively applying naked singles (cells with one valid candidate)
class SimpleSolver : public Solver
{
public:
    std::optional<Board> Solve(const Board& board) override;

private:
    // Returns all valid candidates for a given empty cell
    std::vector<Move> GetCandidates(const Board& board, int row, int col) const;

    // Finds the first naked single and returns the resulting board, or nullopt
    std::optional<Board> ApplyNakedSingle(const Board& board) const;
};