#include <cstddef>
#include <cstdlib>
#include <string>

using namespace std;

typedef string::size_type sz;
string screen(sz ht = 24, sz wd = 80, char backgrnd = ' ');

inline const string &
shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}

constexpr int new_sz() { return 42; }
constexpr int foo = new_sz();

constexpr size_t scale(size_t cnt) { return new_sz() * cnt; }
constexpr size_t scale2(size_t cnt) {
    return new_sz() * cnt;
}

int main (int argc, char *argv[])
{
    string window;

    window = screen();
    window = screen(66);
    window = screen(66, 256);
    window = screen(66, 256, '#');

    return 0;
}
