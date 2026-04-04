// Lets's create a shopping cart and a product class

#include<bits/stdc++.h>
using namespace std;


// Product 
class Product{
    public:
    string name;
    double price;

    Product(string name,int price){
        this->name = name;
        this->price = price;
    }
};

//  The below class voilating the SRP (single responsibility principle)
// Shopping cart
class ShoppingCart{
    private:
    vector<Product*>products;
    
    public:
    void addProduct(Product* p){
        products.push_back(p);
    }

    vector<Product*> getProduct(){
        return products;
    }

    // Calculate total_price
    double totalPrice(){
        double total_sum = 0;
        
        for(auto p:products){
            total_sum += p->price;
        }

        return total_sum;
    }

    // Print Invoice  Should be in separate class(SRP violation)
    void printInvoice(){
        cout<<"Shopping cart Invoice: \n";

        for(auto p:products){
            cout<<p->name <<"- $"<<p->price<<endl;
        }

        cout<<"Total amount: $"<<totalPrice()<<endl;
    }

    // Save to DB  Should be in separate class(SRP violation)
    void saveToDatabase(){
        cout<<"Saving shopping cart to database...."<<endl;
    }
};

int main(){
    ShoppingCart *c = new ShoppingCart();
    
    c->addProduct(new Product("Laptop",45000));
    c->addProduct(new Product("Water Bottle",230));

    c->printInvoice();
    c->saveToDatabase();

    return 0;
}