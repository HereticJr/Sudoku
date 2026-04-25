#include "Board.h"

void Board::read(std::istream& in) {
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            in >> grid[row][col];
        }
    }
}

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

int Board::getCell(int row, int col) const {
    return grid[row][col];
}

void Board::setCell(int row, int col, int value) {
    grid[row][col] = value;
}

bool Board::isValidPlacement(int row, int col, int value) const {
    int oldValue = grid[row][col];

    const_cast<Board*>(this)->grid[row][col] = value;

    bool valid = isRowValid(row) &&
        isColValid(col) &&
        isBoxValid(row - row % 3, col - col % 3);

    const_cast<Board*>(this)->grid[row][col] = oldValue;

    return valid;
}


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