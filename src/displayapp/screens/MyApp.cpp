#include <libraries/log/nrf_log.h>
#include "displayapp/DisplayApp.h"

#include "displayapp/screens/MyApp.h"


using namespace Pinetime::Applications::Screens;

MyApp::MyApp(DisplayApp* app) : Screen(app) {
  // try
  // {
    board.craeteBoard();
  // }
  // catch(const std::exception& e)
  // {
  //   NRF_LOG_INFO("Error.");
  // }
  
  // lv_obj_t* title = lv_label_create(lv_scr_act(), nullptr);
  // lv_label_set_text_static(title, "My test2 application");
  // lv_label_set_align(title, LV_LABEL_ALIGN_CENTER);
  // lv_obj_align(title, lv_scr_act(), LV_ALIGN_CENTER, 0, 0);

}

MyApp::~MyApp() {
  lv_obj_clean(lv_scr_act());
}