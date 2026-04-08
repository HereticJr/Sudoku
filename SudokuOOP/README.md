# Sudoku Board Validator

A C++ program that reads, prints, and validates a 9×9 Sudoku board.

This is **Laboratory Assignment 2** — a refactoring of the procedural solution from Lab 1 into an object-oriented design using a `Board` class.

## Project Structure

```
sudoku/
├── Board.h      # Class declaration
├── Board.cpp    # Class implementation
├── main.cpp     # Entry point
└── README.md
```

## Build Instructions

Using `g++`:

```bash
g++ -std=c++17 -Wall -o sudoku main.cpp Board.cpp
```

Or with `make` (if a Makefile is present):

```bash
make
```

## Run Instructions

```bash
./sudoku
```

The program reads a 9×9 board from standard input.  
Each row must be entered as 9 space-separated integers, where `0` represents an empty cell.

**Example input:**

```
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9
```

**Example output:**

```
 5 3 . | . 7 . | . . .
 6 . . | 1 9 5 | . . .
 . 9 8 | . . . | . 6 .
------+-------+------
 8 . . | . 6 . | . . 3
 4 . . | 8 . 3 | . . 1
 7 . . | . 2 . | . . 6
------+-------+------
 . 6 . | . . . | 2 8 .
 . . . | 4 1 9 | . . 5
 . . . | . 8 . | . 7 9

The board is valid.
```

## Validation Rules

The board is considered **valid** if:
- No row contains duplicate digits (1–9)
- No column contains duplicate digits (1–9)
- No 3×3 box contains duplicate digits (1–9)

Empty cells (value `0`) are ignored during validation.
