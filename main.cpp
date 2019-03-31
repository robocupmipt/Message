#include<iostream>
#include"custom.h"
#include"message.h"

int main(int argc, char *argv[])
{
  int inputType;
  int outputType;

  if(argc != 3)
  {
    std::cout << "Arg error" << std::endl;

    return 1;
  }
  else
  {
    inputType = atoi(argv[1]);
    outputType = atoi(argv[2]);

    std::cout << "types: " << inputType << " " << outputType << std::endl;
  }

  Message<MessageType<Output>, MessageType<Input>> com(inputType, outputType);
  com.InitMsg();

  MessageType<Output> m;
  MessageType<Input> r;
  r.data.Print();

  m.data.Write(3.14, 6.5);
  m.data.Print();
  com.SendMessage(m);

  r = com.ReceiveMessage();
  r.data.Print();
}
