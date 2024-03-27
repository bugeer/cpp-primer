#include "Screen.h"

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

Screen::pos Screen::size() const {
    return height * width;
}

