#include <ios>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    std::string line;
    std::string word;
    char c;

    cout << "Please input some string, input ENTER for end:" << endl;

    while(cin >> word)
    {
        if(cin.get() == '\n')
        {
            line += word;

            break;
        }
        else 
        {
            line += (word + " ");
        }
    }

    cout << "The whole line is: " << endl;
    cout << ">|" << line << "|<" << endl;

    return 0;
}
