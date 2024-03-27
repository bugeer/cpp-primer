#ifndef __WINDOW_MANAGER__
#define __WINDOW_MANAGER__

#include <string>
#include <vector>

class Screen;

class window_manager {
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);

    window_manager();
private:
    std::vector<Screen> screens;
};

#endif // !__WINDOW_MANAGER__
