
# Sudoku Project

## Project Description

This project is part of the **Programming Paradigms** course.
This is the first laboratory assignment for the **Programming Paradigms** course.

The goal of the project is to implement a Sudoku processing system step by step throughout the course.
Each laboratory assignment extends the functionality of this project.

Current functionality:

- Reading a Sudoku board
- Printing a Sudoku board
- Validating whether the board configuration is correct

Future assignments will extend this project with additional functionality such as solving Sudoku puzzles.

---

## Project Structure

Example project structure:

```
Sudoku/
│
├── src/
│   ├── main.cpp
│   ├── sudoku.cpp
│
├── include/
│   ├── sudoku.h
│
└── README.md
```

Your structure may differ, but it should remain clear and organized.

`main.cpp` - Entry point with minimal logic
`sudoku.cpp` - Implementation of core algorithms
`sudoku.h` - Function prototypes and constants

---

## Build Instructions

Example using **g++**:

```
g++ -std=c++17 src/*.cpp -o sudoku
```

If you are using another compiler or build system, update this section accordingly.

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

## Author

Student name: Kremliov Ratmir
Student ID: ? 
