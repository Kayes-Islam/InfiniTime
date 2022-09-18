#include "block_piece.h"
#include "board.h"

// #include "displayapp/icons/Spiderman_240x240.c"

LV_IMG_DECLARE(Spiderman_240x240);

BlockPiece::BlocksMap BlockPiece::blocksMap = init_map();

BlockPiece::BlockPiece() {
  board = NULL;
  imageButton1 = NULL;
}

void BlockPiece::initialize(Board* boardL, int correctIndexL) {
  board = boardL;
  correctIndex = correctIndexL;
  imageButton1 = lv_img_create(lv_scr_act(), NULL);

  // lv_obj_align(img1, NULL, LV_ALIGN_CENTER, 0, -20);

  lv_img_set_auto_size(imageButton1, false);
  lv_point_t correctIndexPoint = BlockPiece::getPointFromIndex(correctIndex);

  lv_img_set_src(imageButton1, &Spiderman_240x240);
  lv_img_set_offset_x(imageButton1, MA_BLOCK_SIZE_X * correctIndexPoint.x);
  lv_img_set_offset_y(imageButton1, MA_BLOCK_SIZE_Y * correctIndexPoint.y);

  lv_obj_set_width(imageButton1, MA_BLOCK_SIZE_X);
  lv_obj_set_height(imageButton1, MA_BLOCK_SIZE_Y);

  lv_obj_set_click(imageButton1, true);
  blocksMap[imageButton1] = this;
  lv_obj_set_event_cb(imageButton1, onItemClicked);
}

void BlockPiece::onItemClicked(lv_obj_t* obj, lv_event_t event) {
  if (BlockPiece::blocksMap.find(obj) != BlockPiece::blocksMap.end()) {
    switch (event) {
      case LV_EVENT_CLICKED:
        BlockPiece* piece = blocksMap[obj];
        piece->board->onPieceClicked(*piece);
        break;
    }
  }
}

void BlockPiece::updateUi(int currentIndexL) {
  currentIndex = currentIndexL;
  lv_point_t currentIndexPoint = BlockPiece::getPointFromIndex(currentIndex);
  lv_obj_set_x(imageButton1, MA_BLOCK_SIZE_X * currentIndexPoint.x);
  lv_obj_set_y(imageButton1, MA_BLOCK_SIZE_Y * currentIndexPoint.y);
}

lv_point_t BlockPiece::getPointFromIndex(int index) {
  lv_point_t point;
  point.x = index % 4;
  point.y = (index - point.x) / 4;
  return point;
}

int BlockPiece::getCorrectIndex() {
  return correctIndex;
}

int BlockPiece::getCurrentIndex() {
  return currentIndex;
}

BlockPiece::~BlockPiece() {
  if (imageButton1 != NULL) {
    if(BlockPiece::blocksMap.find(imageButton1) != BlockPiece::blocksMap.end()){
      BlockPiece::blocksMap.erase(imageButton1);
    }
    
    lv_obj_clean(imageButton1);
    imageButton1 = NULL;
  }
}