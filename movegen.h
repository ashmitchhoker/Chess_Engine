#pragma once
#include "board.h"
#include "types.h"
#include "eval.h"
#include <utility>

MoveList generateMoves(const Board &board);
void makeMove(Board &board, const Move &m);
void undoMove(Board &board, const Move &m);
