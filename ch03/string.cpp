#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

int main()
{
    {
        string s1;
        string s2 = s1;
        string s3 = "hiya";
        string s4(10, 'c');

        s2 = "fuck";

        cout << "s1: " << s1 << endl;
        cout << "s2: " << s2 << endl;
        cout << "s3: " << s3 << endl;
        cout << "s4: " << s4 << endl;
    }

    {
        cout << endl;
        cout << "some init methods" << endl;
        string s5 = "hiya"; // copy init; may create a temp object;
        string s6("hiya");  // direct init;
        string s7(10, 'c'); // direct init 

        cout << s7.size() << endl;
    }

    // {
    //     cout << endl;
    //     cout << "string IO: please input string s:" << endl;
    //
    //     string s;
    //     cin >> s;
    //     cout << s << endl;
    // }

    {
        string s("some string");
        cout << "The raw string:" << s << endl;
        for(char &c : s)
        {
            c = 'X';
        }

        cout << "The char to X :";
        cout << s << endl;
    }

    {
        string s;
        cout << s.size() << endl;
        cout << s[0] << endl;
    }

    {
        string s = "hello world.";
        // char *str = s;
        const char * str = s.c_str();
    }

    {
        int int_arr[] = {0, 1, 2, 3, 4, 5};
        vector<int> ivec(begin(int_arr), end(int_arr));

        cout << "the vector :" << endl;
        for(int i : ivec)
        {
            cout << i << " ";
        }
        cout << endl;
        cout << endl;

        vector<int> sub_vec(int_arr+1, int_arr+4);
        cout << "the sub vector :" << endl;
        for(int i : sub_vec)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
