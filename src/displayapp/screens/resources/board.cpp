#include <algorithm>
#include <iostream>
#include <map>
#include "board.h"


Board::Board() {
  emptyIndex = 0;
}

void Board::craeteBoard() {
  int indexes[16];
  for (int i = 0; i < 16; i++) {
    indexes[i] = i;
  }

  std::random_shuffle(std::begin(indexes), std::end(indexes));

  for (int i = 0; i < 15; i++) {
    int correctIndex = i + 1;
    pieces[i].initialize(this, correctIndex);
  }

  for (int i = 0; i < 16; i++) {
    if(i == 0){
      emptyIndex = indexes[i];
    }
    else{
      pieces[i - 1].updateUi(indexes[i]);
    }
  }
}

void Board::onPieceClicked(BlockPiece& piece) {
  // check has left piece
  int pieceCurrentIndex = piece.getCurrentIndex();
  lv_point_t pp = BlockPiece::getPointFromIndex(pieceCurrentIndex);
  lv_point_t ep = BlockPiece::getPointFromIndex(emptyIndex);

  bool isMove = false;
  if(pp.x == ep.x){
    isMove = pp.y == (ep.y + 1) || pp.y == (ep.y - 1);
  }
  else if(pp.y == ep.y){
    isMove = pp.x == (ep.x + 1) || pp.x == (ep.x - 1);
  }

  if (isMove) {
    piece.updateUi(emptyIndex);
    emptyIndex = pieceCurrentIndex;
  }
}

Board::~Board() {
}