#include <cstddef>
#include <iostream>
#include <iterator>
#include <string>

using namespace std;

int main (int argc, char *argv[])
{
    {
        string nums[] = {"one", "two", "three"};
        string *p1 = &nums[0];
        string *p2 = nums;

        cout << (p1 == p2) << endl;
    }

    {
        int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        auto ia2(ia); // ia2 is a pointer not an array.

        decltype(ia) ia3 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // ia3 is an array with 10 elements

        int *first = begin(ia);
        int *last  = end(ia);

        cout << (last - first) << endl;
    }

    {
        constexpr size_t sz = 5;
        int arr[sz] = {1, 2, 3, 4, 5};
        int *ip = arr;
        int *ip2 = ip + 4;

        int *p3 = arr + sz;
        int *p4 = arr + 10;

        cout << *p3 << " " << *p4 << endl;
    }

    return 0;
}
