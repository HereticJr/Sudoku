#include "SimpleSolver.h"

bool SimpleSolver::Solve(Board& board)
{
    bool progress = true;

    while (progress)
    {
        progress = fillNakedSingles(board);
    }

    return isSolved(board);
}

// One pass: fills every cell that has exactly one valid candidate
bool SimpleSolver::fillNakedSingles(Board& board) const
{
    bool filled = false;

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
            {
                board.setCell(row, col, candidate);
                filled = true;
            }
        }
    }

    return filled;
}

// Returns true if there are no empty cells remaining
bool SimpleSolver::isSolved(const Board& board) const
{
    for (int row = 0; row < Board::SIZE; ++row)
        for (int col = 0; col < Board::SIZE; ++col)
            if (board.getCell(row, col) == 0)
                return false;

    return true;
}