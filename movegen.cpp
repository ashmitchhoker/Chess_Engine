#include "movegen.h"
#include "board.h"
#include "types.h"
// Directions for sliding pieces
const int bishop_dirs[4] = {9, 7, -7, -9};
const int rook_dirs[4]   = {8, -8, 1, -1};
const int queen_dirs[8]  = {9, 7, -7, -9, 8, -8, 1, -1};

// Knight moves
const int knight_moves[8] = {17, 15, 10, 6, -6, -10, -15, -17};

// King moves
const int king_moves[8] = {1, -1, 8, -8, 9, -9, 7, -7};

inline bool sameRow(int a, int b) {
    return (a / 8) == (b / 8);
}



MoveList generateMoves(const Board &board) {
    MoveList moves;

    for (int sq = 0; sq < 64; sq++) {
        Piece piece = board.squares[sq];
        if (piece == Piece::EMPTY) continue;

        bool isWhite = (piece >= Piece::WP && piece <= Piece::WK);
        if (isWhite != board.whiteToMove) continue;

        switch (piece) {
            case Piece::WP: {
                if (sq + 8 < 64 && board.squares[sq+8] == Piece::EMPTY)
                    moves.push_back({sq, sq+8, Piece::EMPTY});
                // Double push from 2nd rank
                if (sq / 8 == 1 && board.squares[sq+8] == Piece::EMPTY && board.squares[sq+16] == Piece::EMPTY)
                    moves.push_back({sq, sq+16, Piece::EMPTY});
                // Captures
                if (sq % 8 != 0 && sq+7 < 64 && board.squares[sq+7] >= Piece::BP)
                    moves.push_back({sq, sq+7, board.squares[sq+7]});
                if (sq % 8 != 7 && sq+9 < 64 && board.squares[sq+9] >= Piece::BP)
                    moves.push_back({sq, sq+9, board.squares[sq+9]});
                break;
            }
            case Piece::BP: {
                if (sq - 8 >= 0 && board.squares[sq-8] == Piece::EMPTY)
                    moves.push_back({sq, sq-8, Piece::EMPTY});
                // Double push from 7th rank
                if (sq / 8 == 6 && board.squares[sq-8] == Piece::EMPTY && board.squares[sq-16] == Piece::EMPTY)
                    moves.push_back({sq, sq-16, Piece::EMPTY});
                // Captures
                if (sq % 8 != 0 && sq-9 >= 0 && board.squares[sq-9] > Piece::EMPTY && board.squares[sq-9] <= Piece::WK)
                    moves.push_back({sq, sq-9, board.squares[sq-9]});
                if (sq % 8 != 7 && sq-7 >= 0 && board.squares[sq-7] > Piece::EMPTY && board.squares[sq-7] <= Piece::WK)
                    moves.push_back({sq, sq-7, board.squares[sq-7]});
                break;
            }
            case Piece::WN: case Piece::BN: {
                for (int m : knight_moves) {
                    int to = sq + m;
                    if (to < 0 || to >= 64) continue;
                    if ((m == 1 || m == -1 || m == 17 || m == -15) && !sameRow(sq, to)) continue;
                    if ((m == 15 || m == -17) && !sameRow(sq, to)) continue;

                    Piece target = board.squares[to];
                    if (target == Piece::EMPTY || (isWhite && target >= Piece::BP) || (!isWhite && target <= Piece::WK && target != Piece::EMPTY))
                        moves.push_back({sq, to, target});
                }
                break;
            }
            case Piece::WB: case Piece::BB: {
                for (int dir : bishop_dirs) {
                    int to = sq;
                    while (true) {
                        to += dir;
                        if (to < 0 || to >= 64) break;
                        // prevent wrap-around
                        if ((dir == 1 || dir == -1) && !sameRow(to, to - dir)) break;
                        Piece target = board.squares[to];
                        if (target == Piece::EMPTY) {
                            moves.push_back({sq, to, Piece::EMPTY});
                        } else {
                            if ((isWhite && target >= Piece::BP) || (!isWhite && target <= Piece::WK && target != Piece::EMPTY))
                                moves.push_back({sq, to, target});
                            break;
                        }
                    }
                }
                break;
            }
            case Piece::WR: case Piece::BR: {
                for (int dir : rook_dirs) {
                    int to = sq;
                    while (true) {
                        to += dir;
                        if (to < 0 || to >= 64) break;
                        if ((dir == 1 || dir == -1) && !sameRow(to, to - dir)) break;
                        Piece target = board.squares[to];
                        if (target == Piece::EMPTY) {
                            moves.push_back({sq, to, Piece::EMPTY});
                        } else {
                            if ((isWhite && target >= Piece::BP) || (!isWhite && target <= Piece::WK && target != Piece::EMPTY))
                                moves.push_back({sq, to, target});
                            break;
                        }
                    }
                }
                break;
            }
            case Piece::WQ: case Piece::BQ: {
                for (int dir : queen_dirs) {
                    int to = sq;
                    while (true) {
                        to += dir;
                        if (to < 0 || to >= 64) break;
                        if ((dir == 1 || dir == -1) && !sameRow(to, to - dir)) break;
                        Piece target = board.squares[to];
                        if (target == Piece::EMPTY) {
                            moves.push_back({sq, to, Piece::EMPTY});
                        } else {
                            if ((isWhite && target >= Piece::BP) || (!isWhite && target <= Piece::WK && target != Piece::EMPTY))
                                moves.push_back({sq, to, target});
                            break;
                        }
                    }
                }
                break;
            }
            case Piece::WK: case Piece::BK: {
                for (int m : king_moves) {
                    int to = sq + m;
                    if (to < 0 || to >= 64) continue;
                    if ((m == 1 || m == -1) && !sameRow(sq, to)) continue;
                    Piece target = board.squares[to];
                    if (target == Piece::EMPTY || (isWhite && target >= Piece::BP) || (!isWhite && target <= Piece::WK && target != Piece::EMPTY))
                        moves.push_back({sq, to, target});
                }
                break;
            }
        }
    }
    return moves;
}

void makeMove(Board &board, const Move &m) {
    board.squares[m.to] = board.squares[m.from];
    board.squares[m.from] = Piece::EMPTY;
    board.whiteToMove = !board.whiteToMove;
}

void undoMove(Board &board, const Move &m) {
    board.squares[m.from] = board.squares[m.to];
    board.squares[m.to] = m.captured;
    board.whiteToMove = !board.whiteToMove;
}
