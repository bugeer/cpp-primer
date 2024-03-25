#include <cstring>
#include <iostream>

using namespace std;

int main (int argc, char *argv[])
{
    const char ca1[] = "hello ";
    const char ca2[] = "world!";

    char ca3[32];
    char result[64];

    strcpy(ca3, ca1);
    strcat(ca3, ca2);
    strcpy(result, ca3);

    cout << "ca1: " << ca1 << endl;
    cout << "ca2: " << ca2 << endl;
    cout << "ca3: " << ca3 << endl;
    cout << endl;
    cout << "result: " << result << endl;

    return 0;
}
