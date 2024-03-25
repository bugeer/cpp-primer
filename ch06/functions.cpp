#include <initializer_list>
#include <string>
#include <vector>

using namespace std;

void reset(int *i) { *i = 0; }
void reset(int &i) {  i = 0; }

string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
    auto ret = s.size();
    occurs = 0;

    for(decltype(ret) i=0; i!=s.size(); ++i)
    {
        if(s[i] == c)
        {
            if(ret == s.size())
            {
                ret = i;
            }
            ++occurs;
        }
    }

    return ret;
}

vector<string> process()
{
    string expected = "";
    string actual = "ok";

    if(expected.empty())
    {
        return {};
    }
    else if(expected == actual)
    {
        return {"functionX", "okay"};
    }
    else
    {
        return {"functionX", expected, actual};
    }
}

struct Record {};
struct Phone  {};
struct Account{};

Record lookup(Phone);
Record lookup(const Phone);

Record lookup(Account&);
Record lookup(const Account&);

int main (int argc, char *argv[])
{
    {
        int i = 42;
        const int *cp = &i;
        const int &ri = i;
        const int &r2 = 42;
        // int *p = cp;
        // int &r3 = r;
        // int &r4 = 42;
    }

    {
        int i = 0;
        const int ci = i;
        string::size_type ctr = 0;
        reset(&i);
        // reset(&ci);
        reset(i);
        // reset(ci);
        // reset(42);
        // reset(ctr);

        find_char("Hello world.", 'o', ctr);
    }

    {
    }

    return 0;
}
