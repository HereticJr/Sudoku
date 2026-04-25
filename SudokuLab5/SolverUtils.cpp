#include "SolverUtils.h"

Board ApplyMove(const Board& board, const Move& move)
{
    Board next = board;
    next.setCell(move.row, move.col, move.value);
    return next;
}

bool IsSolved(const Board& board)
{
    for (int row = 0; row < Board::SIZE; ++row)
        for (int col = 0; col < Board::SIZE; ++col)
            if (board.getCell(row, col) == 0)
                return false;

    return true;
}

// Finds the first empty cell and returns all valid candidate moves for it
std::vector<Move> GetMoves(const Board& board)
{
    for (int row = 0; row < Board::SIZE; ++row)
    {
        for (int col = 0; col < Board::SIZE; ++col)
        {
            if (board.getCell(row, col) != 0)
                continue;

            std::vector<Move> moves;

            for (int value = 1; value <= Board::SIZE; ++value)
                if (board.isValidPlacement(row, col, value))
                    moves.push_back({ row, col, value });

            return moves;
        }
    }

    return {};
}