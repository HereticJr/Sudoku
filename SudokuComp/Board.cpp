#include "Board.h"

// Read 81 integers (9x9) from the input stream into the grid
void Board::read(std::istream& in) {
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            in >> grid[row][col];
        }
    }
}

// Print the board with grid separators for readability
void Board::print(std::ostream& out) const {
    for (int row = 0; row < SIZE; ++row) {
        if (row > 0 && row % 3 == 0) {
            out << "------+-------+------\n";
        }

        for (int col = 0; col < SIZE; ++col) {
            if (col > 0 && col % 3 == 0) {
                out << " | ";
            }

            if (grid[row][col] == 0) {
                out << '.';
            }
            else {
                out << grid[row][col];
            }

            if (col + 1 < SIZE && (col + 1) % 3 != 0) {
                out << ' ';
            }
        }
        out << '\n';
    }
}

// Validate the entire board by checking all rows, columns, and 3x3 boxes
bool Board::validate() const {
    for (int row = 0; row < SIZE; ++row) {
        if (!isRowValid(row)) return false;
    }
    for (int col = 0; col < SIZE; ++col) {
        if (!isColValid(col)) return false;
    }
    for (int row = 0; row < SIZE; row += 3) {
        for (int col = 0; col < SIZE; col += 3) {
            if (!isBoxValid(row, col)) return false;
        }
    }
    return true;
}

// Return the value stored at (row, col)
int Board::getCell(int row, int col) const {
    return grid[row][col];
}

// Set the value at (row, col)
void Board::setCell(int row, int col, int value) {
    grid[row][col] = value;
}

// Check whether placing 'value' at (row, col) violates any Sudoku rule
bool Board::isValidPlacement(int row, int col, int value) const {
    for (int c = 0; c < SIZE; ++c) {
        if (grid[row][c] == value) return false;
    }

    for (int r = 0; r < SIZE; ++r) {
        if (grid[r][col] == value) return false;
    }

    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int r = startRow; r < startRow + 3; ++r) {
        for (int c = startCol; c < startCol + 3; ++c) {
            if (grid[r][c] == value) return false;
        }
    }

    return true;
}

// Returns true if the given row has no duplicate digits
bool Board::isRowValid(int row) const {
    bool seen[SIZE + 1] = {};
    for (int col = 0; col < SIZE; ++col) {
        int val = grid[row][col];
        if (val == 0) continue;
        if (seen[val]) return false;
        seen[val] = true;
    }
    return true;
}

// Returns true if the given column has no duplicate digits
bool Board::isColValid(int col) const {
    bool seen[SIZE + 1] = {};
    for (int row = 0; row < SIZE; ++row) {
        int val = grid[row][col];
        if (val == 0) continue;
        if (seen[val]) return false;
        seen[val] = true;
    }
    return true;
}

// Returns true if the 3x3 box starting at (startRow, startCol) has no duplicate digits
bool Board::isBoxValid(int startRow, int startCol) const {
    bool seen[SIZE + 1] = {};
    for (int row = startRow; row < startRow + 3; ++row) {
        for (int col = startCol; col < startCol + 3; ++col) {
            int val = grid[row][col];
            if (val == 0) continue;
            if (seen[val]) return false;
            seen[val] = true;
        }
    }
    return true;
}