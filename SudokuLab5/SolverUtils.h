#pragma once

#include <vector>
#include "Board.h"
#include "Move.h"

// Returns a new board with the given move applied, without modifying the original
Board ApplyMove(const Board& board, const Move& move);

// Returns true if the board has no empty cells
bool IsSolved(const Board& board);

// Returns all valid moves for the first empty cell found
std::vector<Move> GetMoves(const Board& board);