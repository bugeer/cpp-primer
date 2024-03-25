#include <iostream>
#include <string>

using namespace std;

bool check_catical(const string &str)
{
    for(const char& c : str)
    {
        if(c >= 'A' && c <= 'Z')
        {
            return true;
        }
    }

    return false;
}

void tolower(string & str)
{
    for(char & c : str)
    {
        if(c >= 'A' && c <= 'Z')
        {
            c += 'a' - 'A';
        }
    }
}

int main (int argc, char *argv[])
{
    string str_check_capital;
    string str_for_lower;

    cout << "Please input a string for checking capital: " <<endl;
    getline(cin, str_check_capital);
    cout << "has capital char " << check_catical(str_check_capital) << endl;;

    cout << endl;

    cout << "Please input a string to lower: " << endl;
    getline(cin, str_for_lower);
    cout << "to lower: " << endl;
    tolower(str_for_lower);
    cout << str_for_lower << endl;

    return 0;
}
