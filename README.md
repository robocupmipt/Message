# Message

Created by Vladislav Molodtsov for communication between modules without naoqi sockets

# Implementation guide for your module

## 1) Copy the following files to your working directory:

```
Channels.h Custom.h Custom.cpp Message.h
```

## 2) Include source file (Custom.cpp) in your CMake file

## 3) Include these .h files to your .h file of your module:

```
#include"Channels.h"
#include"Custom.h"
#include"Message.h"
```
## 4) Add namespace in .h file of your module:

```
using namespace message;
```

## 5) Create private field in class of your module:

```
private:
Message<MessageType<Send>, MessageType<Receive>> message_;
```

## 6) Add constructor of Message class in your constructor:

```
MyModule::MyModule() : message_(FROM_YOUR_MODULE_TO_OTHER, FROM_OTHER_MODULE_TO_YOUR)
```

### Note:
Here FROM\_YOUR\_MODULE\_TO\_OTHER and FROM\_OTHER    \_MODULE\_TO\_YOUR - message types which you can find in channels.h.

## 7) Customize classes Receive and Send, which are in Custom.h Custom.cpp

### Note:
* Class Message uses two templates: one for desctiprion
of received data and one for description of sending data.
* Calls SendMessage and ReceiveMessage work with struct MessageType<T>. It's a template struct, which
contains field data. You can access this field to call your own
methods, that you will write in Custom.h. Also there some examples
next.

## 8) Run endless loop that will receive messages and will call methods of your class

For instance,

```
void StrategyModule::ReceiveLoop()
{
    std::cout << "start receive loop\n";

    while(1)
    {
        MessageType<Receive> buf = ReceiveMessage();

        // Example of using
        currentGameState = buf.data.state;
    }
}
```

and call it (for example, in init()) using std::threads:

```
void StrategyModule::init()
{
    std::thread receive([&](){
        ReceiveLoop();
    });

    receive.detach();
}
```

For more details about threads: [link](//https://en.cppreference.com/w/cpp/thread/thread/detach).

## 9) Write sending messages in your methods:

```
MessageType<Send> buf;

// For example:
buf.data.state = currentGameState;
message_.SendMessage(buf);
```
