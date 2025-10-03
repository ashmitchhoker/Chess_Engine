#pragma once
#include <cstdint>
#include <vector>
#include <string>

// Piece codes
enum Piece {
    EMPTY = 0,
    WP, WN, WB, WR, WQ, WK,
    BP, BN, BB, BR, BQ, BK
};

struct Move {
    int from;
    int to;
    Piece captured = Piece::EMPTY;
};

using MoveList = std::vector<Move>;
