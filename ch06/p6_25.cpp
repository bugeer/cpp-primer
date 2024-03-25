#include <cstring>
#include <iostream>
#include <iterator>
#include <string>

using namespace std;

int main (int argc, char *argv[])
{
    if(argc < 2)
    {
        cout << "ERROR: The argc is lower than 2!" << endl;
        return -1;
    }

    string strs[argc];
    for(int i=0; i<argc; i++)
    {
        strs[i] = string(argv[i]);
    }

    for(int i=0; i<argc; i++)
    {
        cout << "argv[" << i << "]: " << argv[i] <<endl;
    }

    cout << "Concatnate them: " << endl;
    string all;
    for(int i=0; i<argc; i++)
    {
        all += strs[i];
    }
    cout << all << endl;

    return 0;
}
