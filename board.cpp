#include "board.h"

Board::Board() {
    // initial chess position
    squares = {
        WR, WN, WB, WQ, WK, WB, WN, WR,
        WP, WP, WP, WP, WP, WP, WP, WP,
        EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
        EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
        EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
        EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
        BP, BP, BP, BP, BP, BP, BP, BP,
        BR, BN, BB, BQ, BK, BB, BN, BR
    };
    whiteToMove = true; // white starts
}

void printBoard(const Board& board) {
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            Piece p = board.squares[r * 8 + c];
            char ch = '.';
            switch (p) {
                case WP: ch = 'P'; break;
                case WN: ch = 'N'; break;
                case WB: ch = 'B'; break;
                case WR: ch = 'R'; break;
                case WQ: ch = 'Q'; break;
                case WK: ch = 'K'; break;
                case BP: ch = 'p'; break;
                case BN: ch = 'n'; break;
                case BB: ch = 'b'; break;
                case BR: ch = 'r'; break;
                case BQ: ch = 'q'; break;
                case BK: ch = 'k'; break;
                default: break;
            }
            std::cout << ch << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}
