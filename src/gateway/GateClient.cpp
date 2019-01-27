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
            INFO("read header callback-------------:length,,,", length, "   msg length:", read_msg_.body_length());
            if (!ec && read_msg_.decode_header())
            {
                INFO("   decode msg ---------- length:", read_msg_.body_length());
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
            INFO("read body callback -----------------");
            if (!ec)
            {
                std::cout.write(read_msg_.body(), read_msg_.body_length());
                const google::protobuf::Message *protoType = ProtoUtils::msgDecode->getMessageByCmdParam(read_msg_.pmd(), read_msg_.param());
                google::protobuf::Message *message = protoType->New();
                message->ParseFromString(read_msg_.body());

                DecodeMessage(message);

                const google::protobuf::Descriptor *descriptor = message->GetDescriptor();
                INFO("recieve: ", descriptor->name());
                PlatPmd::LoginAccPmd_C2S* loginMessage = dynamic_cast<PlatPmd::LoginAccPmd_C2S*>(message);
                INFO("recieve meesage platform:", loginMessage->platform());
                INFO("recieve meesage channel_open_id:", loginMessage->channel_open_id());
                INFO("recieve meesage game_account_id:", loginMessage->game_account_id());
                INFO("recieve meesage game_account_sign:", loginMessage->game_account_sign());
                INFO("recieve meesage channel_param:", loginMessage->channel_param());

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