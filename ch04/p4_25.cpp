#include <bitset>
#include <iostream>

using namespace std;

int main (int argc, char *argv[])
{
    char c = 'q' + 0;
    char cc = c << 6;
    std::cout << hex << c << endl;
    std::cout << bitset<sizeof(c)*8>(c) << endl;
    std::cout << hex << cc << endl;
    std::cout << bitset<sizeof(cc)*8>(cc) << endl;

    return 0;
}
