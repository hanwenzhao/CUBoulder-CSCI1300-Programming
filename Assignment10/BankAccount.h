#ifndef BANKACCOUNT_H_INCLUDED
#define BANKACCOUNT_H_INCLUDED

class BankAccount{
protected:
    double balance;
    double interest_rate;
public:
    BankAccount(double dollars, double rate);
    double get_balance();
    double get_rate();
    void set(double new_balance, double new_rate);};

#endif // BANKACCOUNT_H_INCLUDED
