# Sudoku Project

## Project Description

This project is part of the **Programming Paradigms** course.
The goal of this assignment is to refactor the Sudoku solver using a **functional programming** approach.

The key idea is eliminating mutable state from the solving logic:
instead of modifying the board in place, each step produces a new board instance.
This removes the need for explicit undo logic during backtracking.

### Current Functionality:
- **Board Management**: Reading from `std::cin`, formatted printing, and full board validation.
- **SimpleSolver**: Iteratively applies naked singles (cells with exactly one valid candidate) using immutable board copies.
- **BacktrackingSolver**: Recursively solves the puzzle by generating moves and applying them to new board instances — no mutation, no undo.
- **Move**: A plain structure representing a single cell assignment (row, col, value).
- **SolverUtils**: Pure helper functions — `ApplyMove`, `IsSolved`, `GetMoves` — shared across solvers.

---

## Project Structure

Example project structure:

```
sudoku/
├── Board.h / Board.cpp           - 9x9 grid representation and validation
├── Move.h                        - Structure representing a single move
├── SolverUtils.h / SolverUtils.cpp - Pure functions: ApplyMove, IsSolved, GetMoves
├── Solver.h                      - Abstract base class with functional interface
├── SimpleSolver.h / SimpleSolver.cpp   - Naked singles strategy (immutable)
├── BacktrackingSolver.h / BacktrackingSolver.cpp - Recursive backtracking (immutable)
└── main.cpp                      - Entry point: read → validate → solve → print
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

The program reads a Sudoku board from standard input (81 integers, zeros represent empty cells).

Example input:
---

## Run Instructions

Example:

```
./sudoku
```

The program expects a Sudoku board from standard input.

Example input:

```
530070000
600195000
098000060
800060003
400803001
700020006
060000280
000419005
000080079
```

---

---

## Solving Strategy

1. **SimpleSolver** is applied first — handles puzzles solvable by logic alone.
2. If the puzzle is not fully solved, **BacktrackingSolver** takes over — handles any valid puzzle.

---

## Author

Student name: Kremliov Ratmir  
Student ID: ?
