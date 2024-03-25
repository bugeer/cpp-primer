#include <cstdio>
#include <iostream>

using namespace std;

unsigned int get_called_count()
{
    static unsigned int called_count = 0;

    return ++called_count;
}

int main (int argc, char *argv[])
{
    cout << get_called_count() << endl;
    cout << get_called_count() << endl;
    cout << get_called_count() << endl;
    cout << get_called_count() << endl;
    cout << get_called_count() << endl;

    return 0;
}
