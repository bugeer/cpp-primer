#include <cctype>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ispunct;

int main (int argc, char *argv[])
{
    {
        string str("some string");

        cout << "|";
        for(auto c: str)
        {
            cout << c << "|";
        }
        cout << endl;
    }
    cout << endl;
    {
        string line;
        decltype(line.size()) punctuationCount = 0;

        cout << "Please input a sentence with punctuations:" << endl;

        getline(cin, line);

        cout << endl;

        for(auto c: line)
        {
            if(ispunct(c)) {
                punctuationCount ++;
            }
        }

        cout << "in sentence: " << endl << endl;
        cout << '\t' << '\"' << line << '\"' << endl << endl;
        cout << "there are " << punctuationCount << " punctuation." << endl;
    }
    cout << endl;
    {
        string s("Hello world!!!");

        cout << "The raw string is: " << endl;
        cout << s << endl << endl;

        for(auto &c : s)
        {
            c = toupper(c);
        }

        cout << "The new string is: " << endl << endl;
        cout << s << endl << endl;
    }

    return 0;
}
