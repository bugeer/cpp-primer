#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main (int argc, char *argv[])
{
    string rawLine;
    string newLine;

    getline(cin, rawLine);

    for(char c : rawLine)
    {
        if(!ispunct(c))
        {
            newLine += c;
        }
    }

    cout << endl << "Raw string is : " << endl << rawLine << endl;
    cout << endl << "New string is : " << endl << newLine << endl;

    return 0;
}
