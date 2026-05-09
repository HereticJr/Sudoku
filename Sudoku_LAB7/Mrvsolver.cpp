#include "Mrvsolver.h"
#include "Solverutils.h"

std::optional<Board> MRVSolver::Solve(const Board& board)
{
    stats = {};
    return SolveImpl(board);
}

std::optional<Board> MRVSolver::SolveImpl(const Board& board)
{
    ++stats.recursiveCalls;

    if (IsSolved(board))
        return board;

    auto cell = SelectMRVCell(board);
    if (!cell)
        return std::nullopt;

    auto [row, col] = *cell;

    for (const auto& move : GetCandidatesForCell(board, row, col))
    {
        ++stats.branchesTried;
        auto result = SolveImpl(ApplyMove(board, move));
        if (result)
            return result;
    }

    return std::nullopt;
}