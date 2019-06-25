#include "BankAccount.h"
#include <iostream>
using namespace std;
BankAccount::BankAccount(double dollars, double rate){
        balance = dollars;
        interest_rate = rate;}
double BankAccount::get_balance(){
    return balance;}
double BankAccount::get_rate(){
    return interest_rate;}
void BankAccount::set(double new_balance, double new_rate){
    balance = new_balance;
    interest_rate = new_rate;}
