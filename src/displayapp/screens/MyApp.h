#pragma once

#include "displayapp/screens/Screen.h"
#include "displayapp/screens/resources/board.h"
#include <lvgl/lvgl.h>

namespace Pinetime {
  namespace Applications {
    namespace Screens {
      class MyApp : public Screen {
      private:
        Board board;
      public:
        MyApp(DisplayApp* app);
        ~MyApp() override;
      };
    }
  }
}