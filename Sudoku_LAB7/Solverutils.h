#pragma once

#include <vector>
#include <functional>
#include <optional>
#include "Board.h"
#include "Move.h"

// --- Validation helpers ---

bool IsRowValid(const Board& board, int row, int col, int value);

bool IsColValid(const Board& board, int row, int col, int value);

bool IsBoxValid(const Board& board, int row, int col, int value);

bool IsValidMove(const Board& board, const Move& move);

// --- Core utilities ---

Board ApplyMove(const Board& board, const Move& move);

bool IsSolved(const Board& board);

// --- Functional utilities ---

using MovePredicate = std::function<bool(const Move&)>;

std::vector<Move> FilterMoves(const std::vector<Move>& moves, MovePredicate predicate);

std::vector<Move> GetCandidatesForCell(const Board& board, int row, int col);

std::vector<Move> GetMoves(const Board& board);

// --- Optimizations ---

// Selects the empty cell with fewest valid candidates (MRV heuristic)
std::optional<std::pair<int, int>> SelectMRVCell(const Board& board);

// Iteratively fills all cells with exactly one candidate; returns nullopt if contradiction is found
std::optional<Board> PropagateForcedMoves(const Board& board);
