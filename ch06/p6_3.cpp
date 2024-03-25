#include <iostream>

using namespace std;

unsigned long long fact(int num)
{
    unsigned long long ret = 1;
    unsigned long long pre = 1;

    while(num > 1)
    {
        pre  = ret;
        ret *= num--;

        if(ret < pre) // maybe try-catch is better.
        {
            cout << "!!! OVERFLOW !!!" << endl;

            return 0;
        }
    }

    return ret;
}

int main (int argc, char *argv[])
{
    int num;

    cin >> num;

    cout << "The factorial of [" << num << "] is :" << endl;
    cout << fact(num) << endl;

    return 0;
}
