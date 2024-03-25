#include <bitset>
#include <iostream>
using namespace std;

void outputUL(unsigned long ul)
{
    cout << "dec: " << ul << " hex: " << hex << ul;
    cout << " bin: " << bitset<sizeof(ul)*8>(ul) << endl;
}

int main (int argc, char *argv[])
{
    unsigned long ul1 = 3;
    unsigned long ul2 = 7;
    unsigned long result;

    cout << "ul1: " << endl;
    outputUL(ul1);
    cout << "ul2: " << endl;
    outputUL(ul2);

    cout << "ul1 &  ul2:" << endl;
    outputUL(ul1 &  ul2);
    cout << "ul1 |  ul2:" << endl;
    outputUL(ul1 |  ul2);
    cout << "ul1 && ul2:" << endl;
    outputUL(ul1 && ul2);
    cout << "ul1 || ul2:" << endl;
    outputUL(ul1 || ul2);

    cout << endl;

    return 0;
}
