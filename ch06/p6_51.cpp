#include <iostream>

using namespace std;

void f()                   { cout << "f()"               << endl; }
void f(int i)              { cout << "f(int)"            << endl; }
void f(int i, int j)       { cout << "f(int, int)"       << endl; }
void f(double i, double j) { cout << "f(double, double)" << endl; }

int calc(int&, int&);
int calc(const int&, const int&);
int calc(char*, char*);
int calc(const char*, const char*);
int calc(char*, char*);
int calc(char* const, char* const);

int main (int argc, char *argv[])
{
    // f(2.56, 42);
    f(42);
    f(42, 0);
    f(2.56, 3.14);

    return 0;
}
