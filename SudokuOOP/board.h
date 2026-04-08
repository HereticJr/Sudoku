#pragma once

#include <iostream>

// Class representing a 9x9 Sudoku board
class Board {
public:
    // Read the board from the given input stream (default: stdin)
    void read(std::istream& in = std::cin);

    // Print the board to the given output stream (default: stdout)
    void print(std::ostream& out = std::cout) const;

    // Validate the board: checks all rows, columns, and 3x3 boxes
    // Returns true if valid, false otherwise
    bool validate() const;

private:
    static const int SIZE = 9;
    int grid[SIZE][SIZE];

    // Check that a single row contains no duplicate non-zero values
    bool isRowValid(int row) const;

    // Check that a single column contains no duplicate non-zero values
    bool isColValid(int col) const;

    // Check that a 3x3 box (top-left corner at startRow, startCol) has no duplicates
    bool isBoxValid(int startRow, int startCol) const;
};