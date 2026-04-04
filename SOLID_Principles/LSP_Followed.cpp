// LSP (Liskove Substitution Principle) Followed
// Child class should always behave like the parent class
// The client should not able to diffrenciate between parent and class

// Use composition instead of inheritance if the subclass doesn't truly "is-a" relationship with the parent class.
// Refactoring Hierarchies: Create separate, smaller interfaces or intermediate classes (e.g., split Bird into FlyingBird and SwimmingBird) 
// rather than forcing a subclass to override methods with exceptions.

// Signature Rule :-  name , return type, argument should be same, Covariance

// Property Rule :- 

// Method Rule :- 


#include<bits/stdc++.h>
using namespace std;

// Only Deposit Account interface
class DepositOnlyAccount{
    public:
    virtual void deposit(double amount)=0;
};


// Only Withdrawable Account interface
class WithdrawableAccount : public DepositOnlyAccount{
    public:
    virtual void withdraw(double amount)=0;
};


// Saving Account contains both deposit() and withdraw() methods.
class SavingAccount : public WithdrawableAccount{
    private:
    double balance;

    public:
    SavingAccount() : balance(0) {}
    
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


// Current Account contains both deposit() and withdraw() methods.
class CurrentAccount : public WithdrawableAccount{
    private:
    double balance;

    public:
    CurrentAccount() : balance(0) {}

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


// FixedTerm Account contains only Deposit method
class FixedTermAccount : public DepositOnlyAccount{
    private:
    double balance;

    public:
    FixedTermAccount() : balance(0) {}
    
    //overriding deposit() method
    void deposit(double amount) override {
        balance += amount;
        cout<<"Deposit: "<<amount<<" in Fixed Term Account Successfully. New Balance: "<<balance<<endl;
    }
};


// Bank Client
class BankClient{
    private:
    vector<DepositOnlyAccount*> depositOnlyAccounts;
    vector<WithdrawableAccount*> withdrawableAccounts;
    
    public:
    BankClient(vector<DepositOnlyAccount*> depositOnlyAccounts,
        vector<WithdrawableAccount*> withdrawableAccounts){
        this->depositOnlyAccounts = depositOnlyAccounts;
        this->withdrawableAccounts = withdrawableAccounts;
    }
    
    void processTransactions(){
        // Withdrawable account transaction process
        for(WithdrawableAccount* acc : withdrawableAccounts){
            acc->deposit(1000);
            acc->withdraw(500);
        }
        
        // Deposit only accounts transaction process
        for(DepositOnlyAccount* acc : depositOnlyAccounts){
            acc->deposit(1000);
        }
    }
};


int main(){
    vector<WithdrawableAccount*> withdrawableAccounts;
    withdrawableAccounts.push_back(new SavingAccount());
    withdrawableAccounts.push_back(new CurrentAccount());

    vector<DepositOnlyAccount*> depositOnlyAccounts;
    depositOnlyAccounts.push_back(new FixedTermAccount());

    BankClient *client = new BankClient(depositOnlyAccounts,withdrawableAccounts);
    client->processTransactions();
    
    return 0;
}
