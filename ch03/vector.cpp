#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main (int argc, char *argv[])
{
    {
        vector<int> ivec;
        vector<string> articles = {"a", "an", "the"}; // list initialize
        vector<int> ivec2(10, -1); // () call construcotr
        vector<string> svec(10, "hi!");
    }

    {
        vector<vector<int>> ivec;
        // vector<string> svec = ivec;
        vector<string> svec(10, "null");
    }

    {
        vector<int> v2;
        for(int i=0; i<100; i++)
        {
            v2.push_back(i);
        }
    }

    // {
    //     string word;
    //     vector<string> text;
    //
    //     while(cin >> word)
    //     {
    //         text.push_back(word);
    //     }
    // }

    {
        vector<int> v{0,1,2,3,4,5,6,7,8,9};
        for(auto &i : v)
        {
            i *= i;
        }
        for(auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
