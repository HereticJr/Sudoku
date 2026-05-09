#include "Solverutils.h"
#include <algorithm>
#include <limits>

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

std::vector<Move> GetCandidatesForCell(const Board& board, int row, int col)
{
    std::vector<Move> all;
    for (int value = 1; value <= Board::SIZE; ++value)
        all.push_back({ row, col, value });

    return FilterMoves(all, [&board](const Move& m) {
        return IsValidMove(board, m);
        });
}

std::vector<Move> GetMoves(const Board& board)
{
    for (int row = 0; row < Board::SIZE; ++row)
    {
        for (int col = 0; col < Board::SIZE; ++col)
        {
            if (board.getCell(row, col) != 0)
                continue;

            return GetCandidatesForCell(board, row, col);
        }
    }

    return {};
}

// --- Optimizations ---

std::optional<std::pair<int, int>> SelectMRVCell(const Board& board)
{
    int bestCount = std::numeric_limits<int>::max();
    std::optional<std::pair<int, int>> bestCell;

    for (int row = 0; row < Board::SIZE; ++row)
    {
        for (int col = 0; col < Board::SIZE; ++col)
        {
            if (board.getCell(row, col) != 0)
                continue;

            int count = static_cast<int>(GetCandidatesForCell(board, row, col).size());

            if (count < bestCount)
            {
                bestCount = count;
                bestCell = { row, col };
            }
        }
    }

    return bestCell;
}

std::optional<Board> PropagateForcedMoves(const Board& board)
{
    Board current = board;

    bool changed = true;
    while (changed)
    {
        changed = false;

        for (int row = 0; row < Board::SIZE; ++row)
        {
            for (int col = 0; col < Board::SIZE; ++col)
            {
                if (current.getCell(row, col) != 0)
                    continue;

                auto candidates = GetCandidatesForCell(current, row, col);

                if (candidates.empty())
                    return std::nullopt; // contradiction

                if (candidates.size() == 1)
                {
                    current = ApplyMove(current, candidates.front());
                    changed = true;
                }
            }
        }
    }

    return current;
}