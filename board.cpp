#include "board.h"

Board::Board() {
    // initial chess position
    squares = {
        Piece::WR, Piece::WN, Piece::WB, Piece::WQ, Piece::WK, Piece::WB, Piece::WN, Piece::WR,
        Piece::WP, Piece::WP, Piece::WP, Piece::WP, Piece::WP, Piece::WP, Piece::WP, Piece::WP,
        Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY,
        Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY,
        Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY,
        Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY, Piece::EMPTY,
        Piece::BP, Piece::BP, Piece::BP, Piece::BP, Piece::BP, Piece::BP, Piece::BP, Piece::BP,
        Piece::BR, Piece::BN, Piece::BB, Piece::BQ, Piece::BK, Piece::BB, Piece::BN, Piece::BR
    };
    whiteToMove = true; // white starts
}

void printBoard(const Board& board) {
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            Piece p = board.squares[r * 8 + c];
            char ch = '.';
            switch (p) {
                case Piece::WP: ch = 'P'; break;
                case Piece::WN: ch = 'N'; break;
                case Piece::WB: ch = 'B'; break;
                case Piece::WR: ch = 'R'; break;
                case Piece::WQ: ch = 'Q'; break;
                case Piece::WK: ch = 'K'; break;
                case Piece::BP: ch = 'p'; break;
                case Piece::BN: ch = 'n'; break;
                case Piece::BB: ch = 'b'; break;
                case Piece::BR: ch = 'r'; break;
                case Piece::BQ: ch = 'q'; break;
                case Piece::BK: ch = 'k'; break;
                default: break;
            }
            std::cout << ch << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}
