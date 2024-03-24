#include <iostream>
#include <vector>

using namespace std;

void output_vector(vector<int>& vec, int i)
{
    if(i < vec.size())
    {
        cout << "vec[" << i << "]: " << vec[i] << endl;

        output_vector(vec, ++i);
    }

}

int main (int argc, char *argv[])
{
    std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    output_vector(vec, 0);

    return 0;
}
