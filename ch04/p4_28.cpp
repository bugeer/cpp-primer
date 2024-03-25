#include <iostream>

using namespace std;

int main (int argc, char *argv[])
{
    cout << "bool     :"<< sizeof(bool     ) << endl;
    cout << "char     :"<< sizeof(char     ) << endl;
    cout << "short    :"<< sizeof(short    ) << endl;
    cout << "int      :"<< sizeof(int      ) << endl;
    cout << "long     :"<< sizeof(long     ) << endl;
    cout << "long long:"<< sizeof(long long) << endl;
    cout << endl;

    cout << "unsigned char     :"<< sizeof(unsigned char     ) << endl;
    cout << "unsigned short    :"<< sizeof(unsigned short    ) << endl;
    cout << "unsigned int      :"<< sizeof(unsigned int      ) << endl;
    cout << "unsigned long     :"<< sizeof(unsigned long     ) << endl;
    cout << "unsigned long long:"<< sizeof(unsigned long long) << endl;
    cout << endl;

    cout << "void     *:"<< sizeof(void     *) << endl;
    cout << "bool     *:"<< sizeof(bool     *) << endl;
    cout << "char     *:"<< sizeof(char     *) << endl;
    cout << "short    *:"<< sizeof(short    *) << endl;
    cout << "int      *:"<< sizeof(int      *) << endl;
    cout << "long     *:"<< sizeof(long     *) << endl;
    cout << "long long*:"<< sizeof(long long*) << endl;
    cout << endl;

    cout << "unsigned char     *:"<< sizeof(unsigned char     *) << endl;
    cout << "unsigned short    *:"<< sizeof(unsigned short    *) << endl;
    cout << "unsigned int      *:"<< sizeof(unsigned int      *) << endl;
    cout << "unsigned long     *:"<< sizeof(unsigned long     *) << endl;
    cout << "unsigned long long*:"<< sizeof(unsigned long long*) << endl;
    cout << endl;

    return 0;
}
