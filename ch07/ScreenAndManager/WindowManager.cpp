#include "WindowManager.h"
#include "Screen.h"

window_manager::window_manager() {
    screens = {Screen(24, 80, ' ')};
}

inline
void window_manager::clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = std::string(s.width*s.height, ' ');
}

