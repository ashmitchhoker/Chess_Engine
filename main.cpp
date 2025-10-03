#include "board.h"
#include "search.h"
#include <iostream>

int main() {
    Board board; // starts in initial position
    printBoard(board);

    auto [score, bestMove] = search(board, 3, -INF, INF);

    std::cout << "Best move: from " << bestMove.from
              << " to " << bestMove.to
              << " (score " << score << ")\n";
}
