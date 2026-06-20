/* Adapter pattern = Wrapper that converts an incompatible interface into the interface expected by the client, 
allowing existing classes to work together without modification. */

// Act as a translater between two or more incompatibel interfaces
// Like language conversion one understand in english but other person don't know hindi so the translater translate it.


#include<iostream>
#include<string>

//Adaptee
class OldPrinter{
    public:
        void oldPrint(std::string msg){
            std::cout<<"Printing: "<<msg<<"\n";
        }
};


// Target Interface
class Printer{
    public:
        virtual void print(std::string msg) = 0;
        virtual ~Printer() {}
};


//Adapter
class PrinterAdapter : public Printer{
    private:
        OldPrinter oldPrinter;
    
    public:
        void print(std::string msg) override{
            oldPrinter.oldPrint(msg);
        }
};


// Client code (main code)
int main(){
    Printer* printer = new PrinterAdapter();
    printer->print("Hello");

    delete printer;
    return 0;
}
