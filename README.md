# Message

Created by Vladislav Molodtsov for communication between modules without naoqi sockets

Implementation guide for your module

1) Copy the following files to your working directory:

Channels.h Custom.h Custom.cpp Message.h

2) Include source file (Custom.cpp) in your CMake file

3) Write this define in your source file with your module:

#define FILE\_KEY "../key"

Warnings: 1. "../key" it is the path to file is called "key", that
should be common for both modules, that communicate with each other
2. This define must be up to the includes from point 3)

3) Include these .h files to your source file with your module:

#include"Channels.h"
#include"Custom.h"
#include"Message.h"

4) Create private field in class of your module:

private:
Message message\_;

5) Add constructor of Message class in your constructor:

MyModule::MyModule(boost::shared\_ptr<AL::ALBroker> broker, const std::string& name) : message\_(FROM\_YOUR\_MODULE\_TO\_OTHER, FROM\_OTHER\_MODULE\_TO\_YOUR)

Note: Here FROM\_YOUR\_MODULE\_TO\_OTHER and FROM\_OTHER    \_MODULE\_TO\_YOUR - message types which you can find in channels.h.

6) Add call of this function in init() of your module:

message\_.InitMsg();

7) Customize classes Receive and Send, which are in Custom.h Custom.cpp

Note: class Message uses two templates: one for desctiprion
of received
data and one for description of sending data.
Calls SendMessage and ReceiveMessage
work with struct MessageType<T>. It's a template struct, which
contains field data. You can access this field to call your own
methods, that you will write in Custom.h. Also there some examples
next.

8) Run endless loop that will receive messages and will call methods of your class

For instance,

void StrategyModule::ReceiveLoop()
{
    std::cout << "start receive loop\n";

    while(1)
    {
        MessageType<Receive> buf = ReceiveMessage();

        currentGameState = buf.data.state;
    }
}

and call it (for example, in init()) using std::threads:

void StrategyModule::init()
{
    std::thread receive([&](){
        ReceiveLoop();
    });

    //https://en.cppreference.com/w/cpp/thread/thread/detach
    receive.detach();
}

9) Write sending messages in your methods:

MessageType<Send> buf;

buf.data.state = currentGameState;
message\_.SendMessage(buf);

