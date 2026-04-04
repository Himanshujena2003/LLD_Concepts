// ISP (Interface Segregation Principle) rule followed

#include<bits/stdc++.h>
using namespace std;


// Interface for 2D shape
class Shape2D{
    public:
    virtual double area()=0;
};


// Interface for 3D shape
class Shape3D{
    public:
    virtual double area()=0;
    virtual double volume()=0;
};


// Square (2d Shape)
class Square : public Shape2D{
    private:
    double side;

    public:
    Square(double s) : side(s) {}

    // overriding area()
    double area() override{
        return side * side;
    }
};


// Rectangle (2d shape)
class Rectangle : public Shape2D{
    private:
    double length;
    double width;

    public:
    Rectangle(double l,double w) : length(l) , width(w){}

    // overriding area()
    double area() override{
        return length * width;
    }
};


// Cube (3d shape)
class Cube : public Shape3D{
    private:
    double side;

    public:
    Cube(double side){
        this->side = side;
    }

    // overriding area() 
    double area() override{
        return 6 * side * side;
    }

    // overriding volume()
    double volume() override{
        return side * side * side;
    }
};


int main(){
    Shape2D *square,*rectangle;
    square = new Square(20);
    rectangle = new Rectangle(12.5,11);

    cout<<"Area of Square: "<<square->area()<<endl;
    cout<<"Area of Rectangle: "<<rectangle->area()<<endl;

    Shape3D *cube = new Cube(23.78);
    cout<<"Area of Cube: "<<cube->area()<<endl;
    cout<<"Volume of Cube: "<<cube->volume()<<endl;
    
    return 0;
}
