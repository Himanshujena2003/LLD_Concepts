// LSP (Liskov Substitution Principle) violation
// Here we are using the exception to resolve the override problem which don't extending
// the parent class behaviour

// Use composition instead of inheritance if the subclass doesn't truly "is-a" relationship with the parent class.
// Refactoring Hierarchies: Create separate, smaller interfaces or intermediate classes (e.g., split Bird into FlyingBird and SwimmingBird) 
// rather than forcing a subclass to override methods with exceptions.

#include<bits/stdc++.h>
using namespace std;

// Account interface
class Account{
    public:
    virtual void deposit(double amount)=0;
    virtual void withdraw(double amount)=0;
};


// Saving Account
class SavingAccount : public Account{
    private:
    double balance;

    public:
    SavingAccount(){
        balance = 0;
    }
    
    // overriding deposit method of account interface
    void deposit(double amount) override{
        balance += amount;
        cout<<"Deposit: "<<amount<<" in Saving Account Successfully. New Balance: "<<balance<<endl;
    }
    
    // overriding withdraw method of account interface
    void withdraw(double amount) override{
        if(balance>=amount){
            balance -= amount;
            cout<<"Withdrawn: "<<amount<<" from Saving Account Successfully. New Balance: "<<balance<<endl;
        }
        else{
            cout<<"Insufficient balance..!"<<endl;
        }
    }
};


// Current Account
class CurrentAccount : public Account{
    private:
    double balance;

    public:
    CurrentAccount(){
        balance = 0;
    }

    // overriding deposit method of account interface
    void deposit(double amount) override{
        balance += amount;
        cout<<"Deposit: "<<amount<<" in Current Account Successfully. New Balance: "<<balance<<endl;
    }

    // overriding withdraw method of account interface
    void withdraw(double amount) override{
        if(balance >= amount){
            balance -= amount;
            cout<<"Withdrawn: "<<amount<<" from Current Account Successfully. New Balance: "<<balance<<endl;
        }
        else{
            cout<<"Insufficient balance..!"<<endl;
        }
    }
};


// Fixed term Account
// Due to this class LSP(Liskov Substitution Principle) Violated
class FixedTermAccount : public Account{
    private:
    double balance;

    public:
    FixedTermAccount(){
        balance = 0;
    }

    //overridinig deposit method of account interface
    void deposit(double amount) override{
        balance += amount;
        cout<<"Deposit: "<<amount<<" in fixed Term Account Successfully. New Balance: "<<balance<<endl;
    }

    // overriding withdraw method of account interface
    // due to this LSP (Liskov Substitution principle) Violated
    // this narrowing the parent properties 
    void withdraw(double amount) override{
        throw logic_error("Withdrawal not possible in Fixed Term Account!");
    }
};


// Bank Client
class BankClient{
    private:
    vector<Account*>accounts;
    
    public:
    BankClient(vector<Account*>accounts){
        this->accounts = accounts;
    }
    
    void processTransactions(){
        for(Account* acc:accounts){
            acc->deposit(1000);

            // if possible withdraw or thow exception
            try{
                acc->withdraw(600);
            }
            catch(exception &e){
                cout<<"Exception: "<<e.what()<<endl;
            }
        }
    }
};


int main(){
    vector<Account*>accounts;
    accounts.push_back(new SavingAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixedTermAccount());

    // let add give it to Bankclient
    BankClient *client = new BankClient(accounts);
    client->processTransactions();
}
