// Factory Method 

// This is a example of Factory Method
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

// Wheat Burger
class BasicWheatBurger : public Burger{
    public:
    void prepare() override{
        cout<<"Create a basic wheat burger consist of latus,ketchup,wheat bun.";
    }
};

class StandardWheatBurger : public Burger{
    public:
    void prepare() override{
        cout<<"Create a standard wheat burger consist of latus,ketchup,chees,wheat bun";
    }
};

class PremiumWheatBurger : public Burger{
    public:
    void prepare() override{
        cout<<"Create a premium wheat burger consisit of latus,mayo,ketchup,chees,aloo patty,wheat bun";
    }
};


//Burger Factory
class BurgerFactory{
    public:
    virtual Burger* createBurger(string type) = 0;
};

class SinghBurger : public BurgerFactory{
    public:
    Burger* createBurger(string type){
        if(type=="Basic")return new BasicBurger();
        else if(type=="Standard") return new StandardBurger();
        else if(type=="Premium") return new PremiumBurger();
        else return NULL;
    }
};

class KingBurger : public BurgerFactory{
    public:
    Burger* createBurger(string type) override{
        if(type=="Basic")return new BasicWheatBurger();
        else if(type=="Standard") return new StandardWheatBurger();
        else if(type=="Premium") return new PremiumWheatBurger();
        else return NULL;
    }
};


int main(){
    string type = "Basic";

    BurgerFactory *factory = new KingBurger();

    Burger*  burger = factory->createBurger(type);

    burger -> prepare();
}