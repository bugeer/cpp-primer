#include <iostream>
#include <string>

using namespace std;

int main (int argc, char *argv[])
{
    string line;
    string vowels;
    int vowelCount = 0;

    cout << "Please input a sentance: " << endl;

    getline(cin, line);

    for(char& i : line)
    {
        if(i == 'a') { ++vowelCount; vowels += 'a'; }
        if(i == 'e') { ++vowelCount; vowels += 'e'; }
        if(i == 'i') { ++vowelCount; vowels += 'i'; }
        if(i == 'o') { ++vowelCount; vowels += 'o'; }
        if(i == 'u') { ++vowelCount; vowels += 'u'; }

        if(i == 'A') { ++vowelCount; vowels += 'A'; }
        if(i == 'E') { ++vowelCount; vowels += 'E'; }
        if(i == 'I') { ++vowelCount; vowels += 'I'; }
        if(i == 'O') { ++vowelCount; vowels += 'O'; }
        if(i == 'U') { ++vowelCount; vowels += 'U'; }

        if(i == ' ' ) { ++vowelCount; vowels += '_' ; }
        if(i == '\t') { ++vowelCount; vowels += "\\t"; }
        if(i == '\n') { ++vowelCount; vowels += "\\n"; }
    }

    cout << endl;
    cout << "In sentance: " << endl;
    cout << line << endl;
    cout << "There are [" << vowelCount << "] vowels or blanks." << endl;
    cout << "And they are :" << vowels << endl;

    return 0;
}
