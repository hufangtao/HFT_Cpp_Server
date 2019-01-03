#include "chat_server.h"

chat_server::chat_server(
    boost::asio::io_context &io_context,
    const tcp::endpoint &endpoint) : acceptor_(io_context, endpoint)
{
    do_accept();
}

void chat_server::do_accept()
{
    std::cout<<"acceptting\n";
    acceptor_.async_accept(
        [this](boost::system::error_code ec, tcp::socket socket) {
            if (!ec)
            {
                std::cout << socket.local_endpoint().address() << " client enter chat room\n";
                std::make_shared<chat_session>(std::move(socket), room_)->start();
            }else{
                std::cout<<"accpet wrong! error msg:"<<ec.message()<<std::endl;
            }
            do_accept();
        });
}