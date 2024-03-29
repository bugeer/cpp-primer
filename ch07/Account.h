#ifndef __ACCOUNT__
#define __ACCOUNT__

#include <string>

class Account {
public:
    void calculate() {
        amount += amount * interestRate;
    }
    static double rate() {
        return interestRate;
    }
    static void rate(double);

private:
    static constexpr int period = 30;
    static double interestRate;
    static double initRate();

    std::string owner;
    double amount;
    double daily_tbl[period];
};

#endif // !__ACCOUNT__
