#include "Numbered.h"

extern void f(Numbered& s);

int main (int argc, char *argv[]) {
    Numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);

    return 0;
}
