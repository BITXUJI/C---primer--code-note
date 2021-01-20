#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

class Account
{
public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double newRate) { interestRate = newRate; }

private:
    std::string owner; //24
    double amount;     //8
    static double interestRate;
    static constexpr double todayRate = 42.42; //
    static double initRate() { return todayRate; }
};

double Account::interestRate = initRate();

#endif // !ACCOUNT_H