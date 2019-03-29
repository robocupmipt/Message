#include"message.h"
#include"custom.h"

template<typename Tx, typename Rx>
Rx Message<Tx, Rx>::receive()
{
  Rx r;
  r.data.Write(0.5, 1.0);
  return r;
}

template<typename Tx, typename Rx>
bool Message<Tx, Rx>::send(Tx & message)
{
  message.data.Print();
}
