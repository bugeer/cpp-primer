#include <cstdlib>
#include <initializer_list>
#include <iostream>
#include <string>

using namespace std;

char &get_value(string &str, string::size_type ix)
{
    return str[ix];
}

int g_ia[10];

int* return_array_pointer(int i)[10]
{
    return g_ia;
}

int main (int argc, char *argv[])
{
    {
        string s("a value");
        cout << "raw string: " << endl;
        cout << s << endl;
        get_value(s, 0) = 'A';
        cout << "after get_value: " <<endl;
        cout << s << endl;
    }

    int arr[10];   // array with 10 int
    int *p1[10];   // array with 10 pointer
    int (*p2)[10]; // pointer to an array with 10 int

    int (*func(int i))[10];

    return 0;
}
