// DIP (Dependency INversion Principle) rule violated

#include<bits/stdc++.h>
using namespace std;

// MongoDb Database (Low-level module)
class MongoDb{
    public:
    void saveToMongo(string data){
        cout<<"Executing MongoDb Function: db.users.insert({name: '"<< data <<"'})"<<endl;
    }
};


// Mysql Database (Low-level module)
class MySqlDb{
    public:
    void saveToMySql(string data){
        cout<<"Executing MySql query: Insert into user values('" << data <<"');"<<endl;
    }
};


// Userservice (High level module)
class UserService{
    private:
    MySqlDb sqlDb;
    MongoDb mongoDb;

    public:
    void storeToMySql(string user){
        sqlDb.saveToMySql(user);
    }

    void storeToMongoDb(string user){
        mongoDb.saveToMongo(user);
    }
};


int main(){
    UserService service;
    service.storeToMongoDb("Himanshu");
    service.storeToMySql("Karan");
}