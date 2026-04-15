/*  It is one of the simplest design pattern. It ensures a class only has one instance
    and provides a global point of access to it.  */

// We can't create more than one instance or object for the class.

/* If there is a realtime usecase where we can access a particular product or any thing
   once then we can use this design pattern there. */
   

// Example code for the above pattern.

#include<iostream>
#include<mutex>

using namespace std;

class Product{
    private:

    static Product* obj;
    static mutex mtx;

    Product(){
        cout<<"I am constructor \n";
    }

    public:
    static Product* getInstance(){
        lock_guard<mutex> lock(mtx); // Lock for thread safety
        if(obj==nullptr){
            obj = new Product();
        }