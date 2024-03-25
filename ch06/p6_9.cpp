#include <iostream>

#include "fact.h"

using namespace std;

int main (int argc, char *argv[])
{
    int num;

    cin >> num;

    cout << "The factorial of [" << num << "] is :" << endl;
    cout << fact(num) << endl;

    return 0;
}
