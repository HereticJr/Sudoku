#include "BacktrackingSolver.h"
#include "SolverUtils.h"
#include <optional>

std::optional<Board> BacktrackingSolver::Solve(const Board& board)
{
    if (IsSolved(board))
        return board;

    for (const auto& move : GetMoves(board))
    {
        Board next = ApplyMove(board, move);
        auto result = Solve(next);

        if (result)
            return result;
    }

    return std::nullopt;
}