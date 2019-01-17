#include "GatewayTcpAcceptor.h"

GatewayTcpAcceptor::GatewayTcpAcceptor(boost::asio::io_context &io_context,
                         const tcp::endpoint &endpoint) : acceptor_(io_context)
{
    do_accept();
}

void GatewayTcpAcceptor::do_accept()
{
    acceptor_.async_accept(
        [this](boost::system::error_code ec, tcp::socket socket) {
            if (!ec)
            {
                std::make_shared<GateClient>(std::move(socket))->start();
            }
            do_accept();
        });
}