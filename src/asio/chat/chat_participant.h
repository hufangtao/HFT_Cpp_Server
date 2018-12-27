#ifndef CHAT_PARTICIPANT_H
#define CHAT_PARTICIPANT_H

#include "common/chat/chat_message.h"
class chat_participant
{
public:
  virtual ~chat_participant();
  virtual void deliver(const chat_message &msg) = 0;
};

#endif