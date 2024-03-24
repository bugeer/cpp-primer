#include <cassert>
#include <cstddef>
#include <iostream>

using namespace std;

void print(const int ia[], std::size_t size)
{
#ifndef NDEBUG
    cerr << __FILE__ << ":" << __LINE__ << ":" << __func__ << ": array size is " << size << endl;
#endif // !NDEBUG
}

int main (int argc, char *argv[])
{
    int ia[10];

    print(ia, 11);

    assert(0);

    std::cout << "asset is fine." << std::endl;

    return 0;
}
