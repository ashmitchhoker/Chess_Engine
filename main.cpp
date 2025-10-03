#include "board.h"
#include "search.h"
#include "movegen.h"
#include <iostream>
#include <string>

std::string squareToAlgebraic(int square) {
    int file = square % 8;
    int rank = square / 8;
    char fileChar = 'a' + file;
    char rankChar = '1' + rank;
    return std::string(1, fileChar) + std::string(1, rankChar);
}

int main() {
    Board board; // starts in initial position
    std::cout << "Initial position:\n";
    printBoard(board);

    // White plays e4 (e2 to e4: square 12 to square 28)
    Move e4(12, 28, Piece::EMPTY);
    makeMove(board, e4);
    
    std::cout << "After 1. e4:\n";
    printBoard(board);

    // Now find best move for black
    auto [score, bestMove] = search(board, 3, -INF, INF);

    std::cout << "Black's best response: " << squareToAlgebraic(bestMove.to) << "\n";
}
