#include "eval.h"

// Piece values
static int piece_values[13] = {
    0, 100, 320, 330, 500, 900, 20000,
    -100, -320, -330, -500, -900, -20000
};

int evaluate(const Board &board) {
    int score = 0;
    for (int sq = 0; sq < 64; sq++) {
        score += piece_values[board.squares[sq]];
    }
    return score;
}
