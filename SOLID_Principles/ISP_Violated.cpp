// ISP (Interface Segrigation Principle) Rule Violated

#include<bits/stdc++.h>
using namespace std;

// Interface For different shapes
class Shape{
    public:
    virtual double area() = 0;
    virtual double volume() = 0;
};


// Square Shape (2D shape)
class Square : public Shape{
    private:
    double side;

    public:
    Square(double s) : side(s) {}

    // overriding area() method
    double area() override{
        return side*side;
    }

    // overriding volume() method , we don't need volume but we have to override
    // It breaks the I (Interface segregation principle)
    double volume() override{
        throw logic_error("Volume not aplicable for Square");
    }
};


// Cube Shape (3D Shape)
class Cube : public Shape{
    private:
    double side;

    public:
    Cube(double s) : side(s) {}

    // overriding area() method
    double area() override{
        return 6 * side * side;
    }

    // overriding volume() method 
    double volume() override{
        return side * side * side;
    }
};


int main(){
    Shape *square = new Square(30.23);
    Shape *cube = new Cube(24.534);

    cout<<"Square area: "<<square->area()<<endl;
    try{
        square->volume();
    }
    catch(exception&e){
        cout<<e.what()<<endl;
    }

    cout<<"Cube area: "<<cube->area()<<endl;
    cout<<"Cube volume: "<<cube->volume()<<endl;

    return 0;
}