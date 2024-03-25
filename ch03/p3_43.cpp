#include <iostream>
#include <iterator>

using namespace std;

int main (int argc, char *argv[])
{
    int ia[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "output array version 1: " << endl;
    for(auto i : ia)
    {
        cout << i << " ";
    }
    cout << endl << endl;

    cout << "output array version 2: " << endl;
    for(int i=0; i<end(ia)-begin(ia); i++)
    {
        cout << ia[i] << " ";
    }
    cout << endl << endl;

    cout << "output array version 3: " << endl;
    for(auto i=begin(ia); i!=end(ia); i++)
    {
        cout << *i << " ";
    }
    cout << endl << endl;

    cout << "output array version 4: " << endl;
    using pi = int *;
    for(pi p=ia; p!=ia+10; ++p)
    {
        cout << *p << " ";
    }

    cout << endl;
    return 0;
}
