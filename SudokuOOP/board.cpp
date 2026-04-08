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
        // Print horizontal separator every 3 rows
        if (row > 0 && row % 3 == 0) {
            out << "------+-------+------\n";
        }

        for (int col = 0; col < SIZE; ++col) {
            // Print vertical separator every 3 columns
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
    // Check all rows
    for (int row = 0; row < SIZE; ++row) {
        if (!isRowValid(row)) return false;
    }

    // Check all columns
    for (int col = 0; col < SIZE; ++col) {
        if (!isColValid(col)) return false;
    }

    // Check all nine 3x3 boxes
    for (int row = 0; row < SIZE; row += 3) {
        for (int col = 0; col < SIZE; col += 3) {
            if (!isBoxValid(row, col)) return false;
        }
    }

    return true;
}

// Returns true if the given row has no duplicate digits (0 is treated as empty)
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