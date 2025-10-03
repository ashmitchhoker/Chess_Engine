# Chess Engine

## Overview
A C++ chess engine implementation featuring basic chess move generation, board evaluation, and alpha-beta pruning search algorithm. The project demonstrates a simple chess AI that can analyze positions and suggest moves.

## Project Structure
- `main.cpp` - Entry point that initializes the board and runs the search
- `board.h/cpp` - Board representation and display functionality
- `types.h` - Core data structures (Move struct, MoveList)
- `movegen.h/cpp` - Chess move generation for all piece types
- `eval.h/cpp` - Position evaluation using material values
- `search.h/cpp` - Alpha-beta pruning search algorithm

## Key Features
- Complete move generation for all chess pieces (pawns, knights, bishops, rooks, queens, kings)
- Material-based position evaluation
- Alpha-beta pruning search algorithm
- Console-based board display

## How to Build
The project uses C++17 and can be compiled with:
```bash
g++ -std=c++17 -o chess main.cpp board.cpp eval.cpp movegen.cpp search.cpp
```

## How to Run
After compilation, simply run:
```bash
./chess
```

The engine will display the initial chess position and suggest the best move based on a depth-3 search.

## Architecture
The chess engine uses an enum class `Piece` to represent piece types, with values for white pieces (WP, WN, WB, WR, WQ, WK) and black pieces (BP, BN, BB, BR, BQ, BK). The board is represented as a 64-element array indexed from 0-63 (a1=0, h8=63).

## Recent Changes
- 2025-10-03: Fixed type inconsistencies between board.h and types.h Piece enums
- 2025-10-03: Successfully compiled and tested chess engine in Replit environment
- 2025-10-03: Set up workflow for automatic compilation and execution
