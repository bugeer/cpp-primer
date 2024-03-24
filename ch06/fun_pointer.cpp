#include <string>

using namespace std;

bool lengthCompare(const string& s1, const string& s2)
{
    return s1.length() >= s2.length();
}

void useBigger(
    const string &s1,
    const string &s2,
    bool pf(const string&, const string &)
);
// equal
void useBigger(
    const string &s1,
    const string &s2,
    bool (*pf)(const string&, const string &)
);

int main (int argc, char *argv[])
{
    bool (*pf)(const string&, const string&);

    pf = lengthCompare;
    pf = &lengthCompare;

    bool b1 = pf("hello", "goodbye");
    bool b2 = (*pf)("hello", "goodbye");
    bool b3 = lengthCompare("hello", "goodbye");

    typedef bool func(const string&, const string&);
    typedef decltype(lengthCompare) func2;

    typedef bool (*func_pointer)(const string&, const string&);
    typedef decltype(lengthCompare) *func_pointer2;

    return 0;
}
