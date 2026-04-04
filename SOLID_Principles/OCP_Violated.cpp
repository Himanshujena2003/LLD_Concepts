#include<bits/stdc++.h>
using namespace std;

class Product{
    public:
    string name;
    int price;
    
    Product(string name,int price){
        this->name = name;
        this->price = price;
    }
};

class ShoppingCart{
    private:
    vector<Product*>products;

    public:
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
// Here we are modifing the code which is not good
class ShoppingCartStorage{
    private:
    ShoppingCart *cart;

    public:
    ShoppingCartStorage(ShoppingCart * cart){
        this->cart = cart;
    }

    void saveToSQLDatabase(){
        cout<<"Saving to sql database...."<<endl;
    }

    void saveToMongoDatabase(){
        cout<<"Saving to mongo database....."<<endl;
    }

    void saveToFile(){
        cout<<"Saving to file....."<<endl;
    }
};

int main(){
    ShoppingCart * c = new ShoppingCart();

    c->addProduct(new Product("Laptop",1500));
    c->addProduct(new Product("Led",1200));

    ShoppingCartPrinter * p = new ShoppingCartPrinter(c);
    p->printInvoice();

    ShoppingCartStorage * s = new ShoppingCartStorage(c);
    s->saveToSQLDatabase();
}
