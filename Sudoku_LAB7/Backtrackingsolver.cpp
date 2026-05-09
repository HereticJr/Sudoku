#include "Backtrackingsolver.h"
#include "Solverutils.h"

std::optional<Board> BacktrackingSolver::Solve(const Board& board)
{
    stats = {};
    return SolveImpl(board);
}

std::optional<Board> BacktrackingSolver::SolveImpl(const Board& board)
{
    ++stats.recursiveCalls;

    if (IsSolved(board))
        return board;

    for (const auto& move : GetMoves(board))
    {
        ++stats.branchesTried;
        auto result = SolveImpl(ApplyMove(board, move));
        if (result)
            return result;
    }

    return std::nullopt;
}