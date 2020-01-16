#include "GateClient.h"

#include "player/PlayerServer.h"

GateClient::GateClient(tcp::socket socket) : socket_(std::move(socket))
{
    // playerServer = std::make_shared<PlayerServer>();
    // playerServer = new PlayerServer(shared_from_this());
}

void GateClient::set_player_server(std::shared_ptr<PlayerServer> playerServer)
{
    this->playerServer = playerServer;
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
            INFO("read header callback-------------:length->", length, "msg length:", read_msg_.body_length());
            std::cout << "msg:" << read_msg_.data() << ":msg end" << std::endl;
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
    std::cout << "do reading body of length:" << read_msg_.body_length() << std::endl;
    auto self(shared_from_this());
    boost::asio::async_read(
        socket_,
        boost::asio::buffer(read_msg_.body(), read_msg_.body_length()),
        [this, self](boost::system::error_code ec, std::size_t length) {
            INFO("read body callback -----------------");
            if (!ec)
            {
                // std::cout.write(read_msg_.body(), read_msg_.body_length());
                const google::protobuf::Message *protoType = ProtoUtils::msgDecode->getMessageByCmdParam(read_msg_.pmd(), read_msg_.param());
                google::protobuf::Message *message = protoType->New();
                message->ParseFromString(read_msg_.body());
                const google::protobuf::Descriptor *descriptor = message->GetDescriptor();
                INFO("recieve: ", descriptor->name());

                PlatPmd::NetPackageNullPmd_C2S* netPackage = dynamic_cast<PlatPmd::NetPackageNullPmd_C2S*>(message);

                std::cout<<"get a "<<netPackage->bitmask()<<std::endl;
                std::cout<<"get a "<<netPackage->bycmd()<<std::endl;
                std::cout<<"get a "<<netPackage->byparam()<<std::endl;

                playerServer->handle_c2s(read_msg_.pmd(), read_msg_.param(), message);

                // handle_c2s(message);

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