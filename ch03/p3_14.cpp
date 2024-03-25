#include <iostream>
#include <vector>

using namespace std;

int main (int argc, char *argv[])
{
    int num;
    vector<int> numbers;

    while(cin >> num)
    {
        numbers.push_back(num);

        if(cin.get() == '\n')
        {
            break;
        }
    }

    cout << "The numbers: " << endl;
    for(int i=0; i<numbers.size(); i++)
    {
        cout << numbers[i] << endl;
    }

    return 0;
}
