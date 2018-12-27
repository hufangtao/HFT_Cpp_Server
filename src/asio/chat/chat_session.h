#ifndef CHAT_SESSION_H
#define CHAT_SESSION_H

#include <boost/asio.hpp>
#include "chat_room.h"
using boost::asio::ip::tcp;

class chat_session : public chat_participant, public std::enable_shared_from_this<chat_session>
{
  public:
    chat_session(tcp::socket socket, chat_room &room);
    void start();
    void deliver(const chat_message &msg);

  private:
    void do_read_header();
    void do_read_body();
    void do_write();

    tcp::socket socket_;
    chat_room &room_;
    chat_message read_msg_;
    chat_message_queue write_msgs_;
};

#endif