#pragma once

#if __has_include("lvgl.h")
  #include "lvgl.h"
#else
  #include "lvgl/lvgl.h"
#endif

#include <iostream>
#include <map>

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
  #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP != 1
  #error "#error LV_COLOR_16_SWAP should be 1 to match SquareLine Studio's settings"
#endif

#ifndef MA_BLOCK_SIZE_X
  #define MA_BLOCK_SIZE_X (LV_HOR_RES / 4)
#endif

#ifndef MA_BLOCK_SIZE_Y
  #define MA_BLOCK_SIZE_Y (LV_VER_RES / 4)
#endif

class Board;

class BlockPiece {
private:
  /* data */
  int correctIndex;
  int currentIndex;
  lv_obj_t* imageButton1;
  typedef std::map<lv_obj_t*, BlockPiece*> BlocksMap;
  static BlocksMap blocksMap;
  static BlocksMap init_map() {
    BlocksMap some_map;
    return some_map;
  }

public:
  Board* board;

  BlockPiece();

  void initialize(Board* boardL, int correctIndexL);

  static void onItemClicked(lv_obj_t* obj, lv_event_t event);

  void updateUi(int currentIndexL);

  static lv_point_t getPointFromIndex(int index);

  int getCorrectIndex();

  int getCurrentIndex();

  ~BlockPiece();
};
