#pragma once
#include <cstdint>
#include <vector>
#include <string>
#include "board.h"

struct Move {
    int from;
    int to;
    Piece captured;
    
    Move(int f = -1, int t = -1, Piece cap = Piece::EMPTY) 
        : from(f), to(t), captured(cap) {}
};

using MoveList = std::vector<Move>;
