#pragma once

#include <optional>
#include "Board.h"

// Abstract base class defining the functional solver interface
class Solver
{
public:
    virtual std::optional<Board> Solve(const Board& board) = 0;
    virtual ~Solver() = default;
};