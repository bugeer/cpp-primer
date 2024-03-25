#include <iostream>

using namespace std;

double absolute(double num)
{
    return num < 0 ? -num : num;
}

int main (int argc, char *argv[])
{
    double num;

    cin >> num;

    cout << "The abs of [" << num << "] is :" << endl;
    cout << absolute(num) << endl;

    return 0;
}
