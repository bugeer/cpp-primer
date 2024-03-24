#include <iostream>
#include <iterator>

using namespace std;

bool compare_arr(int* arr0, int len0, int* arr1, int len1)
{
    if(len0 != len1)
    {
        return false;
    }

    for(int i=0; i<len0; i++)
    {
        if(arr0[i] != arr1[i])
        {
            return false;
        }
    }

    return true;
}

void output_array(int* arr, int len)
{
    for(int i=0; i<len; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main (int argc, char *argv[])
{
    int arr0[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "arr0: " << endl;
    output_array(arr0, end(arr0) - begin(arr0));
    cout << "arr1: " << endl;
    output_array(arr1, end(arr1) - begin(arr1));

    compare_arr(arr0, end(arr0) - begin(arr0), arr1, end(arr1) - begin(arr1))
        ? cout << "the two arrays are the SAME!"     << endl
        : cout << "the two arrays are NOT the same!" << endl;

    return 0;
}
