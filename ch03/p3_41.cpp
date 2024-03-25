#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main (int argc, char *argv[])
{
    int iarr[] = {0, 1, 2, 3, 4, 5};

    vector<int> ivec(begin(iarr), end(iarr));

    cout << "The Array: " << endl;
    for(int i : iarr)
    {
        cout << i << " ";
    }

    cout << endl << endl;

    cout << "The Vector: " << endl;
    for(int i : ivec)
    {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}
