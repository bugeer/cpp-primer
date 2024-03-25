#include <iostream>
#include <string>

using namespace std;

string s10[10] = {
    "string 0",
    "string 1",
    "string 2",
    "string 3",
    "string 4",
    "string 5",
    "string 6",
    "string 7",
    "string 8",
    "string 9",
};

// ?? sure??
typedef string ref_s10[10];

string (&return_10_string_ref())[10]
{
    return s10;
}

auto func() -> string(&)[10];

int odd [] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};

decltype(odd) * arrPtr(int i)
{
    return (i%2) ? &odd : &even;
}

decltype(odd)& arrRef(int i)
{
    return (i%2) ? odd : even;
}

int main (int argc, char *argv[])
{
    string (&s10)[10] = return_10_string_ref();

    for(string & s : s10)
    {
        cout << s << endl;
    }

    return 0;
}
