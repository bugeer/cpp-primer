
#include <iostream>
using namespace std;

int main (int argc, char *argv[])
{
    int num;
    while(cin >> num)
    {
        if(num == 42)
        {
            break;
        }

        cout << "the integer: " << num << endl;
    }

    return 0;
}
