// This design patter is used to add some functionality or some behavior at runtime to an object
// Like adding features to an object without modifying original class

#include<iostream>
#include<string>

// Coffee Interface for different type of coffee //
class ICoffee{
    public:
        virtual int cost() const = 0;
        virtual std::string description() const = 0;
        virtual ~ICoffee() = default;
};


// Different types of coffee //
class SimpleCoffee : public ICoffee{
    public:
        int cost() const override {
            return 100;
        }

        std::string description() const override {
            return "Simple coffee";
        }
};


class Espresso : public ICoffee{
    public:
        int cost() const override {
            return 150;
        }

        std::string description() const override {
            return "Espresso coffee";
        }
};



// Decorators Base //
class CoffeeDecorator : public ICoffee{
    protected:
        ICoffee* coffee;
    
    public: 
        CoffeeDecorator(ICoffee* coffee) : coffee(coffee) {}
};


// Different types of decorators //
class MilkDecorator : public CoffeeDecorator{
    public:
        MilkDecorator(ICoffee* coffee) : CoffeeDecorator(coffee){}

        int cost() const override{
            return coffee->cost() + 20;
        }

        std::string description() const override{
            return coffee->description() + ", Milk";
        }
};


class SugarDecorator : public CoffeeDecorator{
    public:
        SugarDecorator(ICoffee* coffee) : CoffeeDecorator(coffee){}

        int cost() const override{
            return coffee->cost() + 10;
        }

        std::string description() const override{
            return coffee->description() + ", Sugar";
        }
};


class ChocolateDecorator : public CoffeeDecorator{
    public:
        ChocolateDecorator(ICoffee* coffee) : CoffeeDecorator(coffee){}

        int cost() const override{
            return coffee->cost() + 30;
        }

        std::string description() const override{
            return coffee->description() + ", Chocolate";
        }  
};



// Main flow //
int main(){
    ICoffee* coffee = new SimpleCoffee();

    coffee = new MilkDecorator(coffee);
    coffee = new SugarDecorator(coffee);
    coffee = new ChocolateDecorator(coffee);

    std::cout<<"Total cost : "<<coffee->cost()<<"\n";
    std::cout<<coffee->description()<<"\n";

    return 0;

}

