#include <iostream>

using namespace std;

int main (int argc, char *argv[])
{
    {
        int ival = 3.541 + 3;
    }

    {
        unsigned int ui = 5;
        int i = -100;

        cout << ui + i << endl;
    }

    {
        int i=256, j = 1024;
        double slope = static_cast<double>(j) / i;
    }

    return 0;
}
