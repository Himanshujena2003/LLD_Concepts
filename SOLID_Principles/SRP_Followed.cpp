// Shopping cart system Follow SRP (Single Responsibility Principle)

#include<bits/stdc++.h>
using namespace std;

// Product
class Product{
    public:
    string name;
    double price;

    Product(string name,double price){
        this->name = name;
        this->price = price;
    }
};

// Shopping cart
class ShoppingCart{
    private:
    vector<Product*>products;

    public:
    void addProduct(Product*p){
        products.push_back(p);
    }

    vector<Product*> getProducts(){
        return products;
    }

    double totalPrice(){
        double total = 0;

        for(auto p:products){
            total += p->price;
        }

        return total;
    }
};

// Shopping cart invoice printer
class ShoppingCartPrinter{
    private:
    ShoppingCart * cart;
    
    public:
    ShoppingCartPrinter(ShoppingCart* cart){
        this->cart = cart;
    }

    void printInvoice(){
        cout<<"Shopping cart Invoice: \n";

        for(auto p:cart->getProducts()){
            cout<<p->name <<"- $"<<p->price<<endl;
        }

        cout<<"Total price: $"<<cart->totalPrice()<<endl;
    }
};

// Shopping cart save to database
class ShoppingCartStorage{
    private:
    ShoppingCart *cart;

    public:
    ShoppingCartStorage(ShoppingCart * cart){
        this->cart = cart;
    }

    void saveToDatabase(){
        cout<<"Saving to database...."<<endl;
    }
};

int main(){
    ShoppingCart * c = new ShoppingCart();

    c->addProduct(new Product("Laptop",1500));
    c->addProduct(new Product("Led",1200));

    ShoppingCartPrinter * p = new ShoppingCartPrinter(c);
    p->printInvoice();

    ShoppingCartStorage * s = new ShoppingCartStorage(c);
    s->saveToDatabase();
}