#include "chat_room.h"

void chat_room::join(chat_participant_ptr participant)
{
    participants_.insert(participant);
    for (auto msg : recent_msgs_)
    {
        participant->deliver(msg);
    }
}

void chat_room::leave(chat_participant_ptr participant)
{
    participants_.erase(participant);
}

void chat_room::deliver(const chat_message &msg)
{
    recent_msgs_.push_back(msg);
    while (recent_msgs_.size() > MAX_RECENT_MSGS)
    {
        recent_msgs_.pop_front();
    }
    for (auto participant : participants_)
    {
        participant->deliver(msg);
    }
}