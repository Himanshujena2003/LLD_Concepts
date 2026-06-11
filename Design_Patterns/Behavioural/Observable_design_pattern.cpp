#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>


// Abstract observer interface for subscriber (object / consumer)
class ISubscriber{
    public:
        virtual void update() = 0;
        virtual ~ISubscriber() = default;  // virtual destructor
};

// Abstract observable interface for channel (subject / producer)
class IChannel{
    public:
        virtual void subscribe(ISubscriber* subscriber) = 0;
        virtual void unsubscribe(ISubscriber* subscriber) = 0;
        virtual void notifySubscriber() = 0;
        virtual ~IChannel () =  default;
};


// Concrete Subject :  youtube channel that observer can subscribe to
class Channel : public IChannel{
    private:
        std::vector<ISubscriber*> subscribers; // List of subscriber
        std::string name;
        std::string latestVideo; // title of latestvideo uploaded

    public:
        Channel(const std::string& name): name(name) , latestVideo("No video available") {}

        // Implementing subscribe method of Ichannel interface
        void subscribe(ISubscriber* subscriber) override{
            auto it = find(subscribers.begin(),subscribers.end(),subscriber);
            if(it == subscribers.end()){
                subscribers.push_back(subscriber);
            }
        }

        // Implementing unsubscribe method of Ichannel interface
        void  unsubscribe(ISubscriber* subscriber) override{
            auto it = find(subscribers.begin(),subscribers.end(),subscriber);
            if(it != subscribers.end()){
                subscribers.erase(it);
            }
        }

        // Notify all subscribers of the latest video
        void notifySubscriber() override{
            for(ISubscriber* s: subscribers){
                s->update();
            }
        }

        // Upload new video and notify all subscribers
        void uploadVideo(const std::string& title){
            latestVideo = title;
            std::cout<<name<<" Uploaded new video \n";
            notifySubscriber();
        }

        const std::string getVideoData() const{
            return "  Chekout our new video : " + latestVideo + "\n";
        }
};


// Concrete observer (subscriber) : subscribed a youtube channel
class Subscriber : public ISubscriber{
    private:
        std::string name;
        Channel* channel;
    
    public:
    Subscriber(const std::string& name, Channel* channel) : name(name),channel(channel){}

    void update() override {
        std::cout<<"Hey "<< name << "," << channel->getVideoData();
    }
};

int main(){
    //creating a channel and Subscriber
    Channel* channel = new Channel("Yoyo");

    // Createing subscriber
    Subscriber* sub1 = new Subscriber("Himanshu",channel);
    Subscriber* sub2 = new Subscriber("Yash",channel);

    // Himanshu and Yash subscribe to Yoyo channel
    channel->subscribe(sub1);
    channel->subscribe(sub2);

    // Upload a video and both himanshu and yasah will notified
    channel->uploadVideo("Blue eyes");

    // Himanshu unsubscribes
    channel->unsubscribe(sub1);

    //Upload another video
    channel->uploadVideo("Brown rang");

    return 0;
}