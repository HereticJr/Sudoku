#pragma once

#include <iostream>

// Class representing a 9x9 Sudoku board
class Board {
public:
    static const int SIZE = 9;

    void read(std::istream& in = std::cin);

    void print(std::ostream& out = std::cout) const;

    bool validate() const;


    int getCell(int row, int col) const;

    void setCell(int row, int col, int value);

    bool isValidPlacement(int row, int col, int value) const;

private:
    int grid[SIZE][SIZE];

    bool isRowValid(int row) const;

    bool isColValid(int col) const;

    bool isBoxValid(int startRow, int startCol) const;
};
