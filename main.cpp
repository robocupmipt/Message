//
// Created by Vladislav Molodtsov on 2019-03-31.
//

#include<iostream>

/*
 * You should to copy these to your module
 */

/* ------ begin ---- - */

#include"Channels.h"
#include"Custom.h"
#include"Message.h"

using namespace message;

/* ------ end ---- - */


/*
 *
 * This main demostrates work with Message
 *
 */

int main(int argc, char *argv[])
{
  // It this case message types are scanning from console
  int receiveType;
  int sendType;

  if(argc != 3)
  {
    std::cout << "Arg error" << std::endl;

    return 1;
  }
  else
  {
    // The first argument is receive type, the second one -send type
    receiveType = atoi(argv[1]);
    sendType = atoi(argv[2]);

    std::cout << "types: " << receiveType << " " << sendType << std::endl;
  }

  // Create and init object of Message class
  Message<MessageType<Send>, MessageType<Receive>> com(receiveType, sendType);
  com.InitMsg();

  // Create MessageType objects with templates
  // These templates are your own classes (see custom.h)
  MessageType<Send> m;
  MessageType<Receive> r;

  // Your own method for Write (see custom.cpp)
  m.data.Write(3.14, 6.5);

  // Your own method for Print (see custom.cpp)
  m.data.Print();

  // You can send message using the following method:
  com.SendMessage(m);

  // You can receive message using the following method:
  r = com.ReceiveMessage();

  // Your own method for Print (see custom.cpp)
  r.data.Print();

  return 0;
}
