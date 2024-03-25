#include <iostream>

using namespace std;

void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

void swap(int &p, int &q)
{
    int temp = p;
    p = q;
    q = temp;
}

int main (int argc, char *argv[])
{
    int i = 10;
    int j = 42;

    cout << "raw numbers          (i, j) = (" << i << ", " << j << ")" << endl;
    cout << "------------------------------" << endl;
    swap(&i, &j);
    cout << "swapped by pointer   (i, j) = (" << i << ", " << j << ")" << endl;
    swap(i, j);
    cout << "swapped by reference (i, j) = (" << i << ", " << j << ")" << endl;
    return 0;
}
