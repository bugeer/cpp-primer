#ifndef __SCREEN__
#define __SCREEN__

#include <csignal>
#include <ostream>
#include <string>
#include <vector>

class Screen;

class window_manager {
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);

private:
    std::vector<Screen> screens;
};

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

inline
Screen &Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;

    return *this;
}

char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

inline
void Screen::some_member() const {
    ++access_ctr;
}

inline
Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline
Screen &Screen::set(pos row, pos col, char ch) {
    contents[row*width + col] = ch;
    return *this;
}

inline
void window_manager::clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = std::string(s.width*s.height, ' ');
}

#endif // !__SCREEN__
