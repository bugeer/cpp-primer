#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

int main (int argc, char *argv[])
{
    {
        cout << 5 + 10 * 20 / 2 << endl;
    }

    {
        short short_value = 32767;
        short_value += 1;
        cout << "short_value: " << short_value << endl;
    }

    {
        cout << -30 / 3 * 21 % 4 << endl;
    }

    {
        int i;
        double d;
        // d = i = 3.5; // warn
        cout << i << " " << d << endl;

        i = d = 3.5;
        cout << i << " " << d << endl;
    }

    {
        double dval;
        int ival;
        int *pi;

        // dval = ival = pi = 0;
    }

    {
        vector<string> svec = {"Hello", "World!", "fuck off"};
        vector<string>::iterator iter = svec.begin();

        *iter++;
        // (*iter) ++;
        // *iter.empty();
        bool isEmpty = iter->empty();
        // ++*iter; // error
        // iter++->empty(); //warn

        string ss = "fuck off";
        cout << "the string: " << ss <<endl;
        cout << ss.empty() << endl;
    }

    {
        string s = "word";
        string p1 = s + (s[s.size()-1] == 's' ? "" : "s");
    }

    return 0;
}
