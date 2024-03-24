#include <iostream>
#include <vector>
using namespace std;

int (*pf)(int, int);

using FP = int (*)(int, int);

int add(int i, int j) { return i+j; }
int sub(int i, int j) { return i-j; }
int mul(int i, int j) { return i*j; }
int ddd(int i, int j) { return i/j; }

int main (int argc, char *argv[])
{
    int m = 9;
    int n = 3;

    vector<FP> vec = {add, sub, mul, ddd};

    for(int i=0; i<vec.size(); i++)
    {
        cout << "i = " << i << " : "<< vec[i](m, n) << endl;
    }

    return 0;
}
