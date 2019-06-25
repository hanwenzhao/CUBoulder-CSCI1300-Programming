#include <iostream>
#include <string>
#include "BankAccount.h"
#include "Accounts.h"

using namespace std;
/*class BankAccount
{
protected:
    double balance;
    double interest_rate;
public:
    BankAccount(double dollars, double rate){
        balance = dollars;
        interest_rate = rate;
    }
    double get_balance(){
        return balance;
    }
    double get_rate(){
        return interest_rate;
    }
    void set(double new_balance, double new_rate){
        balance = new_balance;
        interest_rate = new_rate;
    }
};

class SavingAccount: public BankAccount
{
private:
public:
    SavingAccount(double dollars, double rate):BankAccount(dollars, rate){
    }
    void deposit(double dollars){
        double balance = get_balance();
        balance = balance + dollars;
        set(balance, get_rate());
    }
    void withdraw(double dollars){
        double balance = get_balance();
        balance = balance - dollars;
        set(balance, get_rate());
    }
};

class CheckingAccount: public BankAccount
{
private:
public:
    CheckingAccount(double dollars, double rate):BankAccount(dollars, rate){
    }
    void deposit(double dollars){
        double balance = get_balance();
        balance = balance + dollars;
        set(balance, get_rate());
    }
    void get_check(double dollars){
        double balance = get_balance();
        balance = balance - dollars;
        set(balance, get_rate());
    }
};

class CDAccount: public BankAccount
{
private:
public:
    CDAccount(double dollars, double rate, double time):BankAccount(dollars, rate){
    }
    void set_rate(double new_rate){
        interest_rate = new_rate;
    }
    void deposit(double dollars){
        double balance;
        balance = balance + dollars;
        set(balance, get_rate());
    }
    double get_estimation(double dollars, double rate, double time){
        double estimation;
        estimation = dollars + dollars * rate/100 * time;
        return estimation;
    }
};*/

int main(){
    cout<<"This is your personal bank, what can I do for you?"<<"\n"<<
    "(s)Create a Saving Account."<<"\n"<<
    "(c)Create a Checking Account."<<"\n"<<
    "(d)Create a CD Account."<<endl;
    string userOpt;
    string userOpt2;
    int done = 0;
    while(not done){
        cin>>userOpt;
        if(userOpt == "s"){
            cout<<"Creating a Saving Account..."<<endl;
            SavingAccount newSaving(0,0.9);
            cout<<"Done!"<<endl;
            cout<<"Your new saving account currently has the balance of "<<newSaving.get_balance()<<".\n"<<endl;
            while(not done){
                cout<<"What would you like to do next?"<<endl;
                cout<<"(d)Deposit"<<"\n"
                <<"(w)Withdraw"<<"\n"
                <<"(q)Quit"<<endl;
                cin>>userOpt2;
                if(userOpt2 == "d"){
                    cout<<"How much money do you want to deposit?"<<endl;
                    double depositMoney;
                    cin>>depositMoney;
                    newSaving.deposit(depositMoney);
                    if(newSaving.get_balance()<0){
                        cout<<"Invalid operate."<<endl;
                        newSaving.withdraw(depositMoney);}
                    cout<<"Your new saving account currently has the balance of "<<newSaving.get_balance()<<".\n"<<endl;}
                if(userOpt2 == "w"){
                    cout<<"How much money do you want to withdraw?"<<endl;
                    double depositMoney;
                    cin>>depositMoney;
                    newSaving.withdraw(depositMoney);
                    if(newSaving.get_balance()<0){
                        cout<<"Invalid operate."<<endl;
                        newSaving.deposit(depositMoney);}
                    cout<<"Your new saving account currently has the balance of "<<newSaving.get_balance()<<".\n"<<endl;}
                if(userOpt2 == "q"){
                    done = 1;}
            }
        }
        else if(userOpt == "c"){
            cout<<"Creating a Checking Account..."<<endl;
            CheckingAccount newChecking(0,0);
            cout<<"Your new checking account currently has the balance of "<<newChecking.get_balance()<<".\n"<<endl;
            cout<<"Done!"<<endl;
            while(not done){
                cout<<"What would you like to do next?"<<endl;
                cout<<"(d)Deposit"<<"\n"
                <<"(c)Get a check"<<"\n"
                <<"(q)Quit"<<endl;
                cin>>userOpt2;
                if(userOpt2 == "d"){
                    cout<<"How much money do you want to deposit?"<<endl;
                    double depositMoney;
                    cin>>depositMoney;
                    newChecking.deposit(depositMoney);
                    if(newChecking.get_balance()<0){
                        cout<<"Invalid operate."<<endl;
                        newChecking.get_check(depositMoney);}
                    cout<<"Your new checking account currently has the balance of "<<newChecking.get_balance()<<".\n"<<endl;}
                if(userOpt2 == "c"){
                    cout<<"How much money do you want for a check?"<<endl;
                    double checkMoney;
                    cin>>checkMoney;
                    newChecking.get_check(checkMoney);
                    if(newChecking.get_balance()<0){
                        cout<<"Invalid operate."<<endl;
                        newChecking.deposit(checkMoney);}
                    cout<<"Your new checking account currently has the balance of "<<newChecking.get_balance()<<".\n"<<endl;}
                if(userOpt2 == "q"){
                    done = 1;}
            }
        }
        else if(userOpt == "d"){
            cout<<"Creating a CD Account..."<<endl;
            CDAccount newCD(0,0,0);
            cout<<"Done!"<<endl;
            while(not done){
                cout<<"What would you like to do next?"<<endl;
                cout<<"(d)Deposit"<<"\n"
                <<"(g)Get a estimation"<<"\n"
                <<"(q)Quit"<<endl;
                cin>>userOpt2;
                if(userOpt2 == "d"){
                    cout<<"How much money do you want to deposit?"<<endl;
                    double depositMoney;
                    cin>>depositMoney;
                    newCD.deposit(depositMoney);
                    cout<<"Your new CD account currently has the balance of "<<newCD.get_balance()<<".\n"<<endl;}
                if(userOpt2 == "g"){
                    double time;
                    cout<<"How long do you want to wait for maturity(years)?"<<endl;
                    cin>>time;
                    newCD.set_rate(0.9*time);
                    cout<<"Your estimation is "<<newCD.get_estimation(newCD.get_balance(),newCD.get_rate(),time)<<" dollars."<<endl;}
                if(userOpt2 == "q"){
                    done = 1;}
            }
        }
        else{
            cout<<"Invalid Choice. Please choose again."<<endl;
        }
        cout<<"Have a nice day!"<<endl;
    }

    return 0;
}
