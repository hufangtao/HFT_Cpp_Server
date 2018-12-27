#include "chat_server.h"

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

chat_session::chat_session(tcp::socket socket, chat_room &room) : socket_(std::move(socket)), room_(room)
{
}
void chat_session::start()
{
    room_.join(shared_from_this());
    do_read_header();
}
void chat_session::deliver(const chat_message &msg)
{
    bool write_in_progress = !write_msgs_.empty();
    write_msgs_.push_back(msg);
    if (!write_in_progress)
    {
        do_write();
    }
}

void chat_session::do_read_header()
{
    auto self(shared_from_this());
    boost::asio::async_read(
        socket_,
        boost::asio::buffer(read_msg_.data(), chat_message::HEADER_LENGTH),
        [this, self](boost::system::error_code ec, std::size_t length) {
            if (!ec && read_msg_.decode_header())
            {
                do_read_body();
            }
            else
            {
                room_.leave(shared_from_this());
            }
        });
}
void chat_session::do_read_body()
{
    auto self(shared_from_this());
    boost::asio::async_read(
        socket_,
        boost::asio::buffer(read_msg_.body(), read_msg_.body_length()),
        [this, self](boost::system::error_code ec, std::size_t length) {
            if (!ec)
            {
                room_.deliver(read_msg_);
                do_read_header();
            }
            else
            {
                room_.leave(shared_from_this());
            }
        });
}
void chat_session::do_write()
{
    auto self(shared_from_this());
    boost::asio::async_write(
        socket_, boost::asio::buffer(write_msgs_.front().data(), write_msgs_.front().length()),
        [this, self](boost::system::error_code ec, std::size_t length) {
            if (!ec)
            {
                write_msgs_.pop_front();
                if (!write_msgs_.empty)
                {
                    do_write();
                }
            }
            else
            {
                room_.leave(shared_from_this());
            }
        });
}

chat_server::chat_server(boost::asio::io_context &io_context,
                         const tcp::endpoint &endpoint) : acceptor_(io_context)
{
    do_accept();
}

void chat_server::do_accept()
{
    acceptor_.async_accept(
        [this](boost::system::error_code ec, tcp::socket socket) {
            if (!ec)
            {
                std::make_shared<chat_session>(std::move(socket), room_)->start();
            }
            do_accept();
        });
}