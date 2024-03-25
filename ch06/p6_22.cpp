#include <iostream>

using namespace std;

void swap_pointer(int *&p, int *&q)
{
    int *t;
    t = p;
    p = q;
    q = t;
}

void swap_pointer(int **p, int **q)
{
    int *t;
    t  = *p;
    *p = *q;
    *q = t;
}

int main (int argc, char *argv[])
{
    int i = 10;
    int j = 42;
    int *p = &i;
    int *q = &j;

    cout << "before swap: (*p, *q) = (" << *p << ", " << *q << ")" << endl;
    swap_pointer(p, q);
    cout << "after  swap: (*p, *q) = (" << *p << ", " << *q << ")" << endl;
    swap_pointer(&p, &q);
    cout << "after  swap: (*p, *q) = (" << *p << ", " << *q << ")" << endl;
    return 0;
}
