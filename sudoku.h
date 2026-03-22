#ifndef SUDOKU_H
#define SUDOKU_H

// Константа размера поля
const int GRID_SIZE = 9;

// Прототипы функций
void readBoard(int board[GRID_SIZE][GRID_SIZE]);
void printBoard(const int board[GRID_SIZE][GRID_SIZE]);
bool isBoardValid(const int board[GRID_SIZE][GRID_SIZE]);

// Вспомогательные функции
bool checkRows(const int board[GRID_SIZE][GRID_SIZE]);
bool checkColumns(const int board[GRID_SIZE][GRID_SIZE]);
bool checkSubgrids(const int board[GRID_SIZE][GRID_SIZE]);

#endif
