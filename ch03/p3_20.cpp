#include <iostream>
#include <vector>

using namespace std;

int main (int argc, char *argv[])
{
    std::vector<float> numbers;
    float num;

    while(cin >> num)
    {
        numbers.push_back(num);

        if(cin.get() == '\n')
        {
            break;
        }
    }

    cout << "output the sum of neighbors: " << endl;
    for(int i=1; i<numbers.size(); i++)
    {
        cout << "<" << i-1 << ", " << i << "> : " << numbers[i] + numbers[i-1] << endl;
    }

    cout << endl;

    cout << "output the sum of the two sides: " << endl;
    auto size = numbers.size();
    for(int i=0; i<(size + 1)/2; i++)
    {
        cout << "<" << i << ", " << size-i-1 << "> : " << numbers[i] + numbers[size-i-1] << endl;
    }

    cout << endl;

    return 0;
}
