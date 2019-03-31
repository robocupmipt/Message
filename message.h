#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#include<sys/msg.h>
#include<errno.h>
#include<stdio.h>

#include"custom.h"
#include"channels.h"

#define FILE_KEY "../key"

#define PERMISSION 0777

#define CHECK(nameFunction, retValue)				\
do {								\
	if(retValue == -1)					\
	{							\
    perror(nameFunction);\
    return false;   \
	}							\
	else							\
		printf("%s succeeded\n", nameFunction);		\
} while(0)							\

/* --------------------- Private classes -------------------- */

template<typename T>
struct MessageType
{
  long type;

  T data;
};

template<typename Tx, typename Rx>
class Message
{
  public:
  Message(int outputType, int inputType);

  bool InitMsg();
  bool SetMessageTypes(int output, int input);

  bool SendMessage(Tx &message);
  Rx ReceiveMessage();

  int msgid_;
  int outputType_ = 1;
  int inputType_ = 2;
};

template<typename Tx, typename Rx>
Message<Tx, Rx>::Message(int outputType, int inputType)
{
  SetMessageTypes(outputType, inputType);
}
template<typename Tx, typename Rx>
bool Message<Tx, Rx>::SetMessageTypes(int outputType, int inputType)
{
  outputType_ = outputType;
  inputType_ = inputType;
}

template<typename Tx, typename Rx>
bool Message<Tx, Rx>::InitMsg()
{
	key_t key = ftok(FILE_KEY, 0);
  CHECK("ftok", key);
  std::cout << "key " << key << std::endl;

	msgid_ = msgget(key, PERMISSION | IPC_CREAT | IPC_EXCL);
	if(msgid_ < 0)
	{
		if(errno == EEXIST)
		{
			msgid_ = msgget(key, PERMISSION);
			CHECK("msgget", msgid_);
		}
		else
		{
      perror("msgget");
			return false;
		}
	}
}

struct Type
{
    long type;

    int data;
};

template<typename Tx, typename Rx>
bool Message<Tx, Rx>::SendMessage(Tx & message)
{
  std::cout << "SendMessage" << std::endl;
  message.type = outputType_;

  std::cout << "type " << message.type << std::endl;
  std::cout << "size " << sizeof(Tx) << std::endl;
  int result = msgsnd(msgid_, (struct msgbuf *)&message, sizeof(Tx), 0);
  CHECK("msgsnd", result);
}

template<typename Tx, typename Rx>
Rx Message<Tx, Rx>::ReceiveMessage()
{
  std::cout << "ReceiveMessage" << std::endl;
  Rx buf;

  std::cout << "size " << sizeof(Rx) << std::endl;

  int length = msgrcv(msgid_, (struct msg_buf *)&buf, sizeof(Rx), inputType_, 0);
  if(length != sizeof(Rx))
  {
    perror("msgrcv");

    std::cout << "Real length = " << length << std::endl;
    std::cout << "Correct length = " << sizeof(Rx) << std::endl;
  }
  else
      std::cout << "msgrcv succeed" << std::endl;

  std::cout << "type " << buf.type << std::endl;

  return buf;
}

#endif /* __MESSAGE_H__ */
