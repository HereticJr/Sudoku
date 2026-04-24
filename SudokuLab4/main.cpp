#include <iostream>
#include "Board.h"
#include "SimpleSolver.h"
#include "BacktrackingSolver.h"

int main()
{
    Board board;
    board.read();

    std::cout << "Initial board:\n";
    board.print();

    if (!board.validate())
    {
        std::cout << "Board is invalid. Cannot solve.\n";
        return 1;
    }

    // Step 1: try to fill obvious cells with SimpleSolver
    Solver* simple = new SimpleSolver();
    bool solvedBySimple = simple->Solve(board);
    delete simple;

    if (solvedBySimple)
    {
        std::cout << "\nSolved by SimpleSolver:\n";
        board.print();
        return 0;
    }

    std::cout << "\nSimpleSolver could not finish. Applying BacktrackingSolver...\n";

    // Step 2: fall back to full backtracking
    Solver* backtracker = new BacktrackingSolver();
    bool solvedByBacktracking = backtracker->Solve(board);
    delete backtracker;

    if (solvedByBacktracking)
    {
        std::cout << "\nSolved by BacktrackingSolver:\n";
        board.print();
    }
    else
    {
        std::cout << "\nNo solution exists.\n";
    }

    return 0;
}