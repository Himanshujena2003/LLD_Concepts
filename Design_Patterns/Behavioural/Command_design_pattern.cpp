#include<iostream>
#include<vector>
using namespace std;

// Command Interface
class ICommand{
    public:
        virtual void execute() = 0;
        virtual void undo() = 0;
        virtual ~ICommand() = default;
};


// Light
class Light{
    public:
        void on(){
            std::cout<<"Light is on"<<"\n";
        }

        void off(){
            std::cout<<"Light is off"<<"\n";
        }
};


// Fan
class Fan{
    public:
        void on(){
            std::cout<<"fan is on"<<"\n";
        }

        void off(){
            std::cout<<"Fan is off"<<"\n";
        }
};


// Concret command on light
class LightCommand : public ICommand{
    private:
        Light* light;
    
    public:
        LightCommand(Light* light) : light(light) {}

        void execute() override{
            light->on();
        }

        void undo() override{
            light->off();
        }
};


// Concrete command for fan
class FanCommand : public ICommand{
    private:
        Fan* fan;

    public:
        FanCommand(Fan* fan) : fan(fan) {}
        
        void execute() override{
            fan->on();
        }

        void undo() override{
            fan->off();
        }
};



// Request Invoker : Remote conntroller for light and fan functionality
class RemoteController{
    private:
        static const int n = 4;
        std::vector<ICommand*>buttons;
        std::vector<bool>buttonPressed;

    public:
        RemoteController(){
            buttons.resize(n,nullptr);
            buttonPressed.resize(n,false);
        }


        void setCommand(int idx,ICommand* cmd){
            if(idx>=0 && idx<n){
                if(buttons[idx] != nullptr) delete buttons[idx];
                buttons[idx]=cmd;
                buttonPressed[idx]=false;
            }
        }  

        void pressButton(int idx){
            if(idx>=0 && idx<n && buttons[idx]!=nullptr){
                if(buttonPressed[idx]==false){
                    buttons[idx]->execute();
                }
                else{
                    buttons[idx]->undo();
                }
                buttonPressed[idx] = !buttonPressed[idx];
            }
            else{
                cout<<"No command assigned at button "<<idx<<endl;
            }
        }

        ~RemoteController(){
            for(int i=0;i<n;i++){
                if(buttons[i]!=NULL){
                    delete buttons[i];
                }
            }
        }
};


int main(){
    Light* light = new Light();
    Fan* fan = new Fan();

    RemoteController* remote = new RemoteController();

    //set command
    remote->setCommand(0,new LightCommand(light));
    remote->setCommand(1,new FanCommand(fan));

    remote->pressButton(0);
    remote->pressButton(0);

    remote->pressButton(1);
    remote->pressButton(1);

    remote->pressButton(2);

    delete remote;
    delete light;
    delete fan;

    return 0;
}