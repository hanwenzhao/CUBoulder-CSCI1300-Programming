#ifndef ACCOUNTS_H_INCLUDED
#define ACCOUNTS_H_INCLUDED
#include "BankAccount.h"
class SavingAccount: public BankAccount{
private:
public:
    SavingAccount(double dollars, double rate);
    void deposit(double dollars);
    void withdraw(double dollars);};

class CheckingAccount: public BankAccount{
private:
public:
    CheckingAccount(double dollars, double rate);
    void deposit(double dollars);
    void get_check(double dollars);};

class CDAccount: public BankAccount{
private:
public:
    CDAccount(double dollars, double rate, double time);
    void set_rate(double new_rate);
    void deposit(double dollars);
    double get_estimation(double dollars, double rate, double time);};

#endif // ACCOUNTS_H_INCLUDED
