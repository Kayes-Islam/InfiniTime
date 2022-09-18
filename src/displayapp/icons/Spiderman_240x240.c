#pragma once

#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_SPIDERMAN_240X240
#define LV_ATTRIBUTE_IMG_SPIDERMAN_240X240


const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_SPIDERMAN_240X240 uint8_t Spiderman_240x240_map[] = {
  /*Pixel format: Red: 5 bit, Green: 6 bit, Blue: 5 bit BUT the 2 bytes are swapped*/
  0xff,
};

const lv_img_dsc_t Spiderman_240x240 = {
  .header.cf = LV_IMG_CF_TRUE_COLOR,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 240,
  .header.h = 240,
  .data_size = 57600 * LV_COLOR_SIZE / 8,
  .data = Spiderman_240x240_map,
};

#endif