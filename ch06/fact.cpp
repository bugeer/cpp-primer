#include <iostream>

unsigned long long fact(int num)
{
    unsigned long long ret = 1;
    unsigned long long pre = 1;

    while(num > 1)
    {
        pre  = ret;
        ret *= num--;

        if(ret < pre) // maybe try-catch is better.
        {
            std::cout << "!!! OVERFLOW !!!" << std::endl;

            return 0;
        }
    }

    return ret;
}
