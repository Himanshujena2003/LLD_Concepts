#ifndef USER_H
#define USER_H

#include<bits/stdc++.h>
#include "Cart.h"
using namespace std;

class User{
    private:
        int userId;
        string name;
        string location;
        Cart *c;
    
    public:
        User(const string& name,const string& location, int userId){
            this->name = name;
            this->location = location;
            this->userId = userId;
            c = new Cart();
        } 
        
        
};

#endif