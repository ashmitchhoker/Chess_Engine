#ifndef SEARCH_H
#define SEARCH_H

#include "board.h"
#include "movegen.h"
#include "types.h"
#include "eval.h"
#include <utility>

const int INF = 100000;

std::pair<int, Move> search(Board& board, int depth, int alpha, int beta);

#endif
