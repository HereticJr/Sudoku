#include "SimpleSolver.h"
#include "SolverUtils.h"
#include <optional>

std::optional<Board> SimpleSolver::Solve(const Board& board)
{
    Board current = board;

    while (true)
    {
        auto next = applyNakedSingle(current);

        if (!next)
            break;

        current = *next;
    }

    if (IsSolved(current))
        return current;

    return std::nullopt;
}

// Scans the board for a cell with exactly one valid candidate and returns a new board with it filled
std::optional<Board> SimpleSolver::applyNakedSingle(const Board& board) const
{
    for (int row = 0; row < Board::SIZE; ++row)
    {
        for (int col = 0; col < Board::SIZE; ++col)
        {
            if (board.getCell(row, col) != 0)
                continue;

            int candidate = 0;
            int count = 0;

            for (int value = 1; value <= Board::SIZE; ++value)
            {
                if (board.isValidPlacement(row, col, value))
                {
                    ++count;
                    candidate = value;
                }
            }

            if (count == 1)
                return ApplyMove(board, { row, col, candidate });
        }
    }

    return std::nullopt;
}