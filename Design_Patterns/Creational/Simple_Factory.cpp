// Simple factory ( it is like a principle not a method of design)

// A factory class that decides which concrete class to initiate

// Here i am taking a "Burger Factory" example

#include<bits/stdc++.h>
using namespace std;

// Abstract Burger class
class Burger{
    public:
    virtual void prepare() = 0;
    virtual ~Burger(){};
};

class BasicBurger : public Burger{
    public:
    void prepare() override{
        cout<<"Create a basic burger consist of latus,ketchup,bun";
    }
};

class StandardBurger : public Burger{
    public:
    void prepare() override{
        cout<<"Create a standard burger consist of latus,ketchup,chees,bun";
    }
};

class PremiumBurger : public Burger{
    public:
    void prepare() override{
        cout<<"Create a premium burger consisit of latus,mayo,ketchup,chees,aloo patty,bun";
    }
};


// Burger factory has-a relato=ion eith burger 
class BurgerFactory{
    public:
    Burger* createBurger(string type){
        if(type=="Basic")return new BasicBurger();
        else if(type=="Standard") return new StandardBurger();
        else if(type=="Premium") return new PremiumBurger();
        else return NULL;
    }
};

int main(){
    BurgerFactory *burger = new BurgerFactory();
    Burger *new_burger = burger->createBurger("Standard");
    new_burger -> prepare();

}