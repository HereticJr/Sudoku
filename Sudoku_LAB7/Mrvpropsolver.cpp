#include "Mrvpropsolver.h"
#include "Solverutils.h"

std::optional<Board> MRVPropSolver::Solve(const Board& board)
{
    stats = {};
    return SolveImpl(board);
}

std::optional<Board> MRVPropSolver::SolveImpl(const Board& board)
{
    ++stats.recursiveCalls;

    auto propagated = PropagateForcedMoves(board);
    if (!propagated)
        return std::nullopt; // contradiction detected during propagation

    if (IsSolved(*propagated))
        return propagated;

    auto cell = SelectMRVCell(*propagated);
    if (!cell)
        return std::nullopt;

    auto [row, col] = *cell;

    for (const auto& move : GetCandidatesForCell(*propagated, row, col))
    {
        ++stats.branchesTried;
        auto result = SolveImpl(ApplyMove(*propagated, move));
        if (result)
            return result;
    }

    return std::nullopt;
}