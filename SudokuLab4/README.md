# Sudoku Project

## Project Description

This project is part of the **Programming Paradigms** course.
The goal of the assignment is to implement a Sudoku processing and solving system using C++.

The project demonstrates the use of Object-Oriented Programming (OOP) principles, specifically polymorphism and abstraction, to implement different solving strategies.

### Current Functionality:
- **Board Management**: Reading from `std::cin`, formatted printing, and full board validation.
- **SimpleSolver**: An algorithm that fills "naked singles" (cells with only one possible candidate).
- **BacktrackingSolver**: A recursive depth-first search algorithm to solve complex puzzles by trying all possibilities.
- **Validation**: Checks rows, columns, and 3x3 grids for consistency.

---

## Project Structure

The project follows a modular structure to separate logic from representation:

- `main.cpp` - Entry point: handles the flow of the program (read -> validate -> solve -> print).
- `Board.h` / `Board.cpp` - Core logic for the 9x9 Sudoku grid.
- `Solver.h` - Abstract base class defining the interface for all solver types.
- `SimpleSolver.h` / `SimpleSolver.cpp` - Strategy for filling obvious cells.
- `BacktrackingSolver.h` / `BacktrackingSolver.cpp` - Strategy for exhaustive search.

---

## Build Instructions

To compile the project using **g++** with C++17 support:

```bash
g++ -std=c++17 *.cpp -o sudoku_solver


---

## Run Instructions

Example:

```
./sudoku_solver
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

## Author

Student name: Kremliov Ratmir
Student ID: ? 
