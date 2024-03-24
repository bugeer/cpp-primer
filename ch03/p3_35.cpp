#include <iostream>
#include <iterator>

using namespace std;

void outputArray(int* arr, int len)
{
    for(int i=0; i<len; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main (int argc, char *argv[])
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "the raw array: " << endl;
    outputArray(arr, end(arr) - begin(arr));

    for(int* i = arr; i != end(arr); i++)
    {
        *i = 0;
    }

    cout << "after:" << endl;
    outputArray(arr, end(arr) - begin(arr));

    return 0;
}
