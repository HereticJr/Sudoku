#include "SolverUtils.h"
#include <algorithm>

// --- Validation helpers ---

bool IsRowValid(const Board& board, int row, int col, int value)
{
    for (int c = 0; c < Board::SIZE; ++c)
        if (c != col && board.getCell(row, c) == value)
            return false;
    return true;
}

bool IsColValid(const Board& board, int row, int col, int value)
{
    for (int r = 0; r < Board::SIZE; ++r)
        if (r != row && board.getCell(r, col) == value)
            return false;
    return true;
}

bool IsBoxValid(const Board& board, int row, int col, int value)
{
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int r = startRow; r < startRow + 3; ++r)
        for (int c = startCol; c < startCol + 3; ++c)
            if (r != row && c != col && board.getCell(r, c) == value)
                return false;

    return true;
}

bool IsValidMove(const Board& board, const Move& move)
{
    return IsRowValid(board, move.row, move.col, move.value) &&
        IsColValid(board, move.row, move.col, move.value) &&
        IsBoxValid(board, move.row, move.col, move.value);
}

// --- Core utilities ---

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

// --- Functional utilities ---

std::vector<Move> FilterMoves(const std::vector<Move>& moves, MovePredicate predicate)
{
    std::vector<Move> result;
    std::copy_if(moves.begin(), moves.end(), std::back_inserter(result), predicate);
    return result;
}

std::vector<Move> GetMoves(const Board& board)
{
    for (int row = 0; row < Board::SIZE; ++row)
    {
        for (int col = 0; col < Board::SIZE; ++col)
        {
            if (board.getCell(row, col) != 0)
                continue;

            std::vector<Move> candidates;
            for (int value = 1; value <= Board::SIZE; ++value)
                candidates.push_back({ row, col, value });

            return FilterMoves(candidates, [&board](const Move& m) {
                return IsValidMove(board, m);
                });
        }
    }

    return {};
}