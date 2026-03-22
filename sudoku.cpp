#include <iostream>
#include <vector>
#include "sudoku.h"

// 1. Чтение доски
void readBoard(int board[GRID_SIZE][GRID_SIZE]) {
    // В задании сказано, что формат ввода можно выбрать свой
    // Я, пожалуй, использую стандартный: 9 строк по 9 цифр :)
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            std::cin >> board[i][j];
        }
    }
}

// 2. Печать доски
void printBoard(const int board[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; ++i) {
        // Делю по горизонтали 3x3
        if (i % 3 == 0 && i != 0) std::cout << "------+-------+------" << std::endl;

        for (int j = 0; j < GRID_SIZE; ++j) {
            // Делю по вертикали 3x3
            if (j % 3 == 0 && j != 0) std::cout << "| ";
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Функция-помощник для проверки повторов в массиве из 9 элементов
bool hasDuplicates(const std::vector<int>& unit) {
    bool seen[10] = { false }; // Массив для отслеживания цифр 1-9
    for (int num : unit) {
        if (num != 0) { // Пустые клетки, то бишь 0-и, игнорируем 
            if (seen[num]) return true; // Дубликат
            seen[num] = true;
        }
    }
    return false;
}

// 3. Проверка строк
bool checkRows(const int board[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; ++i) {
        std::vector<int> row;
        for (int j = 0; j < GRID_SIZE; ++j) row.push_back(board[i][j]);
        if (hasDuplicates(row)) return false;
    }
    return true;
}

// 4. Проверка столбцов
bool checkColumns(const int board[GRID_SIZE][GRID_SIZE]) {
    for (int j = 0; j < GRID_SIZE; ++j) {
        std::vector<int> col;
        for (int i = 0; i < GRID_SIZE; ++i) col.push_back(board[i][j]);
        if (hasDuplicates(col)) return false;
    }
    return true;
}

// 5. Проверка решеток 3x3
bool checkSubgrids(const int board[GRID_SIZE][GRID_SIZE]) {
    for (int rowStart = 0; rowStart < GRID_SIZE; rowStart += 3) {
        for (int colStart = 0; colStart < GRID_SIZE; colStart += 3) {
            std::vector<int> block;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    block.push_back(board[rowStart + i][colStart + j]);
                }
            }
            if (hasDuplicates(block)) return false;
        }
    }
    return true;
}

// Главная функция валидации
bool isBoardValid(const int board[GRID_SIZE][GRID_SIZE]) {
    return checkRows(board) && checkColumns(board) && checkSubgrids(board);
}