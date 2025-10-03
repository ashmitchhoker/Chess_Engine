#include "search.h"
#include "board.h"
#include "movegen.h"
#include "types.h"
#include "eval.h"
#include <utility>


std::pair<int, Move> search(Board& board, int depth, int alpha, int beta) {
    if (depth == 0) {
        return { evaluate(board), Move() };
    }

    auto moves = generateMoves(board);
    if (moves.empty()) {
        return { evaluate(board), Move() };
    }

    Move bestMove;
    int bestScore = -INF;

    for (auto& m : moves) {
        Piece captured = board.squares[m.to];
        makeMove(board, m);

        int score = -search(board, depth - 1, -beta, -alpha).first;
        
        undoMove(board, m); // ✅ only 1 argument now


        if (score > bestScore) {
            bestScore = score;
            bestMove = m;
        }
        if (bestScore > alpha) alpha = bestScore;
        if (alpha >= beta) break; // alpha-beta pruning
    }
    return { bestScore, bestMove };
}
