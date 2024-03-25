#include <iostream>

using namespace std;

int get_bigger(int i, int* const p)
{
    return i > *p ? i : *p;
}

int main (int argc, char *argv[])
{
    int i = 10;
    int j = 42;
    int *p = &j;

    cout << "the bigger number is: " << get_bigger(i, p) << endl;

    return 0;
}
