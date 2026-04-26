#pragma once

#include <vector>
#include <functional>
#include "Board.h"
#include "Move.h"

// --- Validation helpers ---

bool IsRowValid(const Board& board, int row, int col, int value);

bool IsColValid(const Board& board, int row, int col, int value);

bool IsBoxValid(const Board& board, int row, int col, int value);

bool IsValidMove(const Board& board, const Move& move);

Board ApplyMove(const Board& board, const Move& move);

bool IsSolved(const Board& board);

using MovePredicate = std::function<bool(const Move&)>;

std::vector<Move> FilterMoves(const std::vector<Move>& moves, MovePredicate predicate);

std::vector<Move> GetMoves(const Board& board);