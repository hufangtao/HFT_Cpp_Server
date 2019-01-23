#include "GateClient.h"

GateClient::GateClient(tcp::socket socket) : socket_(std::move(socket))
{
}
void GateClient::start()
{
    do_read_header(); //  开始处理消息
}

void GateClient::do_read_header()
{
    std::cout << "do reading header\n";
    auto self(shared_from_this());
    boost::asio::async_read(
        socket_,
        boost::asio::buffer(read_msg_.data(), ProtoMessage::HEADER_LENGTH + ProtoMessage::PMD_LENGTH + ProtoMessage::PARAM_LENGTH),
        [this, self](boost::system::error_code ec, std::size_t length) {
            if (!ec && read_msg_.decode_header())
            {
                do_read_body();
            }
            else
            {
                std::cout << ec.message() << std::endl;
            }
        });
}
void GateClient::do_read_body()
{
    std::cout << "do reading body\n";
    auto self(shared_from_this());
    boost::asio::async_read(
        socket_,
        boost::asio::buffer(read_msg_.body(), read_msg_.body_length()),
        [this, self](boost::system::error_code ec, std::size_t length) {
            if (!ec)
            {
                // std::cout << "length: " << length << "  body_length" << read_msg_.body_length() << "\n";
                std::cout.write(read_msg_.body(), read_msg_.body_length());
                const google::protobuf::Message *protoType = ProtoUtils::msgDecode->getMessageByCmdParam(read_msg_.pmd(), read_msg_.param());
                auto message = protoType->New();
                // set data in message
                message->ParseFromString(read_msg_.body());

                // 把message交给server处理
                
                // room_.deliver(read_msg_);
                do_read_header();
            }
            else
            {
                std::cout << ec.message() << std::endl;
            }
        });
}
void GateClient::do_write()
{
}