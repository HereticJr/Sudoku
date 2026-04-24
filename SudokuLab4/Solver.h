#pragma once

#include "Board.h"

// Abstract base class defining the solver interface
class Solver
{
public:
    virtual bool Solve(Board& board) = 0;
    virtual ~Solver() = default;
};