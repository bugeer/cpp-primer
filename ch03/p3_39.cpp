#include <iostream>
#include <string>

using namespace std;

#define MaxCStringLen 256

int compare_string(string& s1, string& s2)
{
    int i=0;

    for(i=0; i<s1.length() && i<s2.length(); i++)
    {
        if(s1[i] - s2[i])
        {
            return s1[i] - s2[i];
        }
    }

    if(s1.length() > s2.length())
    {
        return s1[i];
    } 
    else if(s1.length() < s2.length())
    {
        return -s2[i];
    }

    return 0;
}

int compare_c_string(char* s1, char* s2)
{
    for(int i=0; i<MaxCStringLen; i++)
    {
        if(s1[i] - s2[i])
        {
            return s1[i] - s2[i];
        }
        else if(!s1[i])
        {
            return 0;
        }
    }

    return 0;
}

int main (int argc, char *argv[])
{
    string s1;
    string s2;

    char cs1[MaxCStringLen];
    char cs2[MaxCStringLen];

    cout << "Please input the first string : " << s1;
    cin >> s1;
    cout << "Please input the second string: " << s2;
    cin >> s2;
    cout << "The result of comparation of the two string: "
         << compare_string(s1, s2)
         << endl;

    cout << "Please input the first c string : " << cs1;
    cin >> cs1;
    cout << "Please input the second c string: " << cs2;
    cin >> cs2;
    cout << "The result of comparation of the two string: "
         << compare_c_string(cs1, cs2)
         << endl;

    return 0;
}
