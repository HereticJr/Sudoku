#include "SimpleSolver.h"
#include "SolverUtils.h"

// Returns all valid moves for a specific empty cell using FilterMoves
std::vector<Move> SimpleSolver::GetCandidates(const Board& board, int row, int col) const
{
    std::vector<Move> all;
    for (int value = 1; value <= Board::SIZE; ++value)
        all.push_back({ row, col, value });

    return FilterMoves(all, [&board](const Move& m) {
        return IsValidMove(board, m);
        });
}

// Scans the board for a naked single (exactly one valid candidate) and applies it
std::optional<Board> SimpleSolver::ApplyNakedSingle(const Board& board) const
{
    for (int row = 0; row < Board::SIZE; ++row)
    {
        for (int col = 0; col < Board::SIZE; ++col)
        {
            if (board.getCell(row, col) != 0)
                continue;

            auto candidates = GetCandidates(board, row, col);

            if (candidates.size() == 1)
                return ApplyMove(board, candidates.front());
        }
    }

    return std::nullopt;
}

std::optional<Board> SimpleSolver::Solve(const Board& board)
{
    Board current = board;

    while (true)
    {
        auto next = ApplyNakedSingle(current);

        if (!next)
            break;

        current = *next;
    }

    if (IsSolved(current))
        return current;

    return std::nullopt;
}