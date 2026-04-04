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


// Shopping abstract persistence
// Abstract class
class Persistence{
    private:
    ShoppingCart * cart;

    public:
    virtual void save(ShoppingCart *cart)=0;
};


// Derived classes
// SQL database
class SQLPersistence : public Persistence{
    public:
    void save(ShoppingCart* cart) override{
        cout<<"Saving to SQL....."<<endl;
    }
};


// MongoDb Database
class MongoPersistence : public Persistence{
    public:
    void save(ShoppingCart* cart) override{
        cout<<"Saving to Mongo....."<<endl;
    }
};


// File
class FilePersistence : public Persistence{
    public:
    void save(ShoppingCart* cart) override{
        cout<<"Saving to File....."<<endl;
    }
};


int main(){
    ShoppingCart * c = new ShoppingCart();

    c->addProduct(new Product("Laptop",1500));
    c->addProduct(new Product("Led",1200));

    ShoppingCartPrinter * p = new ShoppingCartPrinter(c);
    p->printInvoice();

    Persistence *sql = new SQLPersistence();
    Persistence *Mongo = new MongoPersistence();
    Persistence *File = new FilePersistence();
 
    sql->save(c);  // Save to sql
    Mongo->save(c);  // Save to Mongo
    File->save(c);  // Save to File
}
