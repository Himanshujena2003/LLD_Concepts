// DIP (Dependency Inversion Principle) Followed

#include<bits/stdc++.h>
using namespace std;

// Abstraction (Interface)
class Database{
    public:
    virtual void save(string data) = 0;
};


// MySql Database (Low-level module)
class MySqlDatabase : public Database{
    public:
    void save(string data) override{
        cout<<"Executing MySql query: Insert into user values('" << data <<"');"<<endl;
    }
};


// MongoDB database (Low-level module)
class MongoDBDatabase : public Database{
    public:
    void save(string data) override{
        cout<<"Executing MongoDb Function: db.users.insert({name: '"<< data <<"'})"<<endl;
    }
};


// Userservice (High-level module)
class UserService{
    private:
    Database *db;     // Dependency Injection

    public:
    UserService(Database* db){
        this->db = db;
    }

    void storeUser(string user){
        db->save(user);
    }
};


int main(){
    MySqlDatabase *mysql;
    MongoDBDatabase *mongodb;

    UserService service1(mysql);
    service1.storeUser("Himanshu");

    UserService service2(mongodb);
    service2.storeUser("Karan");
}