# Sudoku Project

## Project Description

This project is part of the **Programming Paradigms** course.

The goal of this assignment is to improve the Sudoku solver by applying **functional composition** and **data transformation** techniques:

- Replace imperative loops with composable operations
- Decompose complex logic into smaller, single-responsibility functions
- Pass functions as parameters using `std::function`
- Improve readability and flexibility of the code

The core principle remains the same as in the previous assignment: the input board is **never modified** — each step produces a new board instance, eliminating the need for explicit undo logic.

---

## What Changed in This Assignment (Lab 6)

### Decomposed Validation Logic (`SolverUtils`)

Validation was split into three focused functions:

```cpp
bool IsRowValid(const Board& board, int row, int col, int value);
bool IsColValid(const Board& board, int row, int col, int value);
bool IsBoxValid(const Board& board, int row, int col, int value);
```

Combined into:

```cpp
bool IsValidMove(const Board& board, const Move& move);
```

### Introduced `FilterMoves` with a Predicate

```cpp
using MovePredicate = std::function<bool(const Move&)>;

std::vector<Move> FilterMoves(const std::vector<Move>& moves, MovePredicate predicate);
```

Used in both `GetMoves` and `SimpleSolver::GetCandidates`:

```cpp
return FilterMoves(candidates, [&board](const Move& m) {
    return IsValidMove(board, m);
});
```

### Separated Generation and Filtering in `GetMoves`

```
1. Generate all candidate moves (values 1–9) for the first empty cell
2. Filter valid ones using FilterMoves + IsValidMove
```

### Refactored `SimpleSolver`

Extracted `GetCandidates(board, row, col)` — returns all valid moves for a specific cell — and simplified `ApplyNakedSingle` to use it.

---

## Project Structure

```
sudoku/
├── Board.h / Board.cpp                           - 9x9 grid representation and validation
├── Move.h                                        - Structure representing a single move (row, col, value)
├── SolverUtils.h / SolverUtils.cpp               - IsRowValid, IsColValid, IsBoxValid, IsValidMove,
│                                                   ApplyMove, IsSolved, FilterMoves, GetMoves
├── Solver.h                                      - Abstract base class with functional interface
├── SimpleSolver.h / SimpleSolver.cpp             - Naked singles strategy (immutable, composable)
├── BacktrackingSolver.h / BacktrackingSolver.cpp - Recursive backtracking (immutable)
└── main.cpp                                      - Entry point: read → validate → solve → print
```

---

## Solver Interface

All solvers implement the following interface:

```cpp
std::optional<Board> Solve(const Board& board);
```

- The input board is **never modified**
- Returns a solved board if a solution exists, or `std::nullopt` otherwise

---

## Solving Strategy

1. **SimpleSolver** is applied first — handles puzzles solvable by logic alone (naked singles).
2. If the puzzle is not fully solved, **BacktrackingSolver** takes over — handles any valid puzzle via recursive backtracking.

---

## Build Instructions

Requires **C++17** or later.

```bash
g++ -std=c++17 *.cpp -o sudoku_solver
```

Or in Visual Studio: `Project → Properties → C/C++ → Language → C++ Language Standard → ISO C++17`

---

## Run Instructions

```bash
./sudoku_solver
```

The program reads a Sudoku board from standard input — 81 space-separated integers, where `0` represents an empty cell.

Example input:

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

Expected output:

```
5 3 4 | 6 7 8 | 9 1 2
6 7 2 | 1 9 5 | 3 4 8
1 9 8 | 3 4 2 | 5 6 7
------+-------+------
8 5 9 | 7 6 1 | 4 2 3
4 2 6 | 8 5 3 | 7 9 1
7 1 3 | 9 2 4 | 8 5 6
------+-------+------
9 6 1 | 5 3 7 | 2 8 4
2 8 7 | 4 1 9 | 6 3 5
3 4 5 | 2 8 6 | 1 7 9
```

---

## Author

Student name: Kremliov Ratmir  
Student ID: ?