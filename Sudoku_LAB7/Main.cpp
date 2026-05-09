#include <iostream>
#include "Board.h"
#include "BacktrackingSolver.h"
#include "MRVSolver.h"
#include "MRVPropSolver.h"

static void PrintStats(const std::string& name, const SolverStats& stats)
{
    std::cout << "[" << name << "]\n";
    std::cout << "  Recursive calls : " << stats.recursiveCalls << "\n";
    std::cout << "  Branches tried  : " << stats.branchesTried << "\n\n";
}

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

    // --- Baseline ---
    BacktrackingSolver baseline;
    baseline.Solve(board);

    // --- MRV ---
    MRVSolver mrv;
    mrv.Solve(board);

    // --- MRV + Propagation ---
    MRVPropSolver mrvProp;
    auto mrvPropResult = mrvProp.Solve(board);

    // --- Print solution ---
    if (mrvPropResult)
    {
        std::cout << "\nSolution:\n";
        mrvPropResult->print();
    }
    else
    {
        std::cout << "\nNo solution exists.\n";
    }

    // --- Compare stats ---
    std::cout << "\n=== Solver Statistics ===\n\n";
    PrintStats("Baseline (first empty cell)", baseline.GetStats());
    PrintStats("MRV", mrv.GetStats());
    PrintStats("MRV + Propagation", mrvProp.GetStats());

    return 0;
}