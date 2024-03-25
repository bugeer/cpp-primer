#include <iostream>
#include <vector>

using namespace std;

int main (int argc, char *argv[])
{
    std::vector<int> ivec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "the raw array: " << endl;
    for(int i : ivec)
    {
        cout << i << " ";
    }
    cout << endl;

    for(int i=0; i<ivec.size(); i++)
    {
        ivec[i] = ivec[i] % 2 == 1 ? ivec[i] *= 2 : ivec[i];
    }
    cout << "after: " << endl;
    for(int i : ivec)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
