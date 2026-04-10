/* The Strategy Pattern defines a family of algorithms, puts each one in a separate 
class, and lets you choose which algorithm to use at runtime. */

// Strategy Pattern = interchangeable behaviors (algorithms) chosen at runtime

// Use when there are multiple ways to perform a task :- payment(upi,card,netbanking)
// Use when you want to switchbehaviour at runtime
// Use when you want to avoid complex conditionals.

// Strategy Interface , Concrete Strategies(different implementation) , Context class(use strategy)

// Implementation example of Robot

#include<bits/stdc++.h>
using namespace std;


// Stategy Talkable Interface
class Talkable{
    public:
    virtual void talk()=0;
    virtual ~Talkable(){}
};

class NormalTalk : public Talkable{
    public:
    void talk() override{
        cout<<"Normal talk \n";
    }
};

class SpecialTalk : public Talkable{
    public:
    void talk() override{
        cout<<"Special talk \n";
    }
};


// Strategy Walkable Interface
class Walkable{
    public:
    virtual void walk()=0;
    virtual ~Walkable(){}
};

class NormalWalk : public Walkable{
    public:
    void walk() override{
        cout<<"Normal walk \n";
    }
};

class SpecialWalk : public Walkable{
    public:
    void walk() override{
        cout<<"Special walk \n";
    }
};


// Strategy Flyable Interface
class Flyable{
    public:
    virtual void fly()=0;
    virtual ~Flyable(){}
};

class NormalFly : public Flyable{
    public:
    void fly() override{
        cout<<"Normal fly \n";
    }
};

class SpecialFly : public Flyable{
    public:
    void fly() override{
        cout<<"Special fly \n";
    }
};


// --- Robot Base class ---
class Robot{
    private:
    Talkable* t;
    Walkable* w;
    Flyable* f;

    public:
    Robot(Talkable* t,Walkable* w,Flyable* f){
        this->t = t;
        this->w = w;
        this->f = f;
    }

    void walk(){
        w->walk();
    }

    void talk(){
        t->talk();
    }

    void fly(){
        f->fly();
    }

    virtual void projection()=0; // Abstract method for subclass
};


// Companion robot
class CompanionRobot : public Robot{
    public:
    CompanionRobot(Talkable* t,Walkable* w,Flyable* f) : Robot(t,w,f){}

    void projection() override{
        cout<<"Display companion features\n";
    }
};


// Worker robot
class WorkerRobot : public Robot{
    public:
    WorkerRobot(Talkable* t,Walkable* w,Flyable* f) : Robot(t,w,f){}

    void projection() override{
        cout<<"Display work stats\n";
    }
};


int main(){
    Robot *robot1 = new CompanionRobot(new NormalTalk(),new NormalWalk(),new SpecialFly());
    robot1->walk();
    robot1->talk();
    robot1->fly();
    robot1->projection();

    Robot *robot2 = new WorkerRobot(new NormalTalk(),new NormalWalk(),new NormalFly());
    robot2->walk();
    robot2->talk();
    robot2->fly();
    robot2->projection();
}