#include<iostream>
#include"message.h"
#include"custom.h"

int main()
{
  Message<MessageType<Output>, MessageType<Input>> com;

  MessageType<Output> m;
  m.data.Write(3.14, 6.5);
  com.send(m);

  MessageType<Input> r = com.receive();
  r.data.Print();
}
