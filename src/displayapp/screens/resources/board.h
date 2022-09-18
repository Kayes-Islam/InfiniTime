#pragma once

#include <algorithm>
#include "block_piece.h"

class Board
{
private:
    BlockPiece pieces[15];
    int emptyIndex;
public:
    Board();

    void craeteBoard();

    void onPieceClicked(BlockPiece &piece);

    ~Board();
};