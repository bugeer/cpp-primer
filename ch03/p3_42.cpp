#include <iostream>
#include <vector>

using namespace std;

int main (int argc, char *argv[])
{
    vector<int> ivec = {0, 1, 2, 3, 4, 5, 6};
    int iarr[ivec.size()];

    for(int i=0; i<ivec.size(); i++)
    {
        iarr[i] = ivec[i];
    }

    cout << "The Vector: " << endl;
    for(int i : ivec)
    {
        cout << i << " ";
    }

    cout << endl << endl;

    cout << "The Array: " << endl;
    for(int i : iarr)
    {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}
