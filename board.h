#ifndef BOARD_H
#define BOARD_H

#include <array>
#include <string>
#include <iostream>

enum class Piece : int {
    EMPTY, WP, WN, WB, WR, WQ, WK,
    BP, BN, BB, BR, BQ, BK
};

struct Board {
    std::array<Piece, 64> squares{};
    bool whiteToMove = true;
    Board();
};


void printBoard(const Board& board);

#endif
