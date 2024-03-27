#ifndef __SCREEN__
#define __SCREEN__

#include <csignal>
#include <ostream>
#include <string>
#include <vector>

#include "WindowManager.h"

class Screen {
public:
    typedef std::string::size_type pos;

    friend void window_manager::clear(std::vector<Screen>::size_type);

    Screen() = default;
    Screen(pos ht, pos wd): height(ht), width(wd) {}
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht*wd, c) {}

    char get() const {
        return contents[cursor];
    }
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);
    Screen &set(char);
    Screen &set(pos, pos, char);
    void some_member() const;
    Screen &display(std::ostream &os) {
        do_display(os);
        return *this;
    }
    const Screen &display(std::ostream &os) const {
        do_display(os);
        return *this;
    }
    pos size() const;

private:
    pos cursor = 0;
    pos height = 0;
    pos width  = 0;
    std::string contents;
    mutable size_t access_ctr;

    void do_display(std::ostream &os) const {
        // os << contents;
        for(size_t row=0; row<width; row++) {
            for(size_t col=0; col<height; col++) {
                os << contents[row*width + col];
            }
            os << std::endl;
        }
    }
};

#endif // !__SCREEN__
