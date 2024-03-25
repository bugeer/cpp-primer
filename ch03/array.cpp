#include <string>

using namespace std;

constexpr int get_size() {
    return 1024;
}

int main (int argc, char *argv[])
{
    {
        unsigned cnt = 42;
        constexpr unsigned sz = 42;
        int arr[10];
        int *parr[sz];
        // string bad[cnt];
        string strs[get_size()];
    }

    {
        const unsigned sz = 3;
        int ial[sz] = {0, 1, 2};
        int a2[ ] = {0, 1, 2};
        int a3[5] = {0, 1, 2};
        string a4[3] = {"hi", "bye"};
        // int a5[2] = {0, 1, 3};
    }

    {
        char a1[] = {'C', '+', '+'};
        char a2[] = {'C', '+', '+', '\0'};
        char a3[] = "C++";
        const char a4[7] = "Daniel"; // 6 is not enough.
    }

    {
        int iarr[10];
        int *ptrs[10];
        // int &refs[10] = /**/ error, no reference array.
        int (*Parray)[10] = &iarr; // Parray point to a array which has 10 elements;
        int (&arrRef)[10] = iarr; // arrRef is a reference which refer to an array with 10 elments;
        int *(&array)[10] = ptrs; // array is a reference whtich refer to an array with 10 pointer;

        // understanding a declear array, the best way is from inside out.
    }

    return 0;
}
