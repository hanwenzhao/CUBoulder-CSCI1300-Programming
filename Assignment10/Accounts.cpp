#include "Accounts.h"
#include <iostream>
using namespace std;

SavingAccount::SavingAccount(double dollars, double rate):BankAccount(dollars, rate){}
void SavingAccount::deposit(double dollars){
    double balance = get_balance();
    balance = balance + dollars;
    set(balance, get_rate());}
void SavingAccount::withdraw(double dollars){
    double balance = get_balance();
    balance = balance - dollars;
    set(balance, get_rate());}

CheckingAccount::CheckingAccount(double dollars, double rate):BankAccount(dollars, rate){}
void CheckingAccount::deposit(double dollars){
    double balance = get_balance();
    balance = balance + dollars;
    set(balance, get_rate());}
void CheckingAccount::get_check(double dollars){
    double balance = get_balance();
    balance = balance - dollars;
    set(balance, get_rate());}

CDAccount::CDAccount(double dollars, double rate, double time):BankAccount(dollars, rate){}
void CDAccount::set_rate(double new_rate){
    interest_rate = new_rate;}
void CDAccount::deposit(double dollars){
    double balance;
    balance = balance + dollars;
    set(balance, get_rate());}
double CDAccount::get_estimation(double dollars, double rate, double time){
    double estimation;
    estimation = dollars + dollars * rate/100 * time;
    return estimation;}
