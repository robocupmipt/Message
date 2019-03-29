#ifndef __MESSAGE_H__
#define __MESSAGE_H__

/* --------------------- Private classes ------------------------- */

template<typename T>
struct MessageType
{
  int type;

  T data;
};

template<typename Tx, typename Rx>
class Message
{
  public:

  bool send(Tx & message);
  Rx receive();
};

#endif /* __MESSAGE_H__ */
