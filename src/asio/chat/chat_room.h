#ifndef CHAT_ROOM_H
#define CHAT_ROOM_H

#include <deque>  // chat_msg_queue
#include <memory> // shared_ptr
#include <set>    // participants
#include "chat_participant.h"

typedef std::deque<chat_message> chat_message_queue;
typedef std::shared_ptr<chat_participant> chat_participant_ptr;

class chat_room
{
public:
  void join(chat_participant_ptr participant);
  void leave(chat_participant_ptr participant);
  void deliver(const chat_message &msg);

private:
  std::set<chat_participant_ptr> participants_;
  enum
  {
    MAX_RECENT_MSGS = 100
  };
  chat_message_queue recent_msgs_;
};

#endif