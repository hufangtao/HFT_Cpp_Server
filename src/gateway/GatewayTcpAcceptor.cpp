#include "GatewayTcpAcceptor.h"

GatewayTcpAcceptor::GatewayTcpAcceptor(boost::asio::io_context &io_context,
                                       const tcp::endpoint &endpoint) : acceptor_(io_context, endpoint)
{
    do_accept();
}

void GatewayTcpAcceptor::do_accept()
{
    INFO("accepting-----------------------------");
    acceptor_.async_accept(
        [this](boost::system::error_code ec, tcp::socket socket) {
            INFO("accept callbakc---------------------------:", ec.message());
            if (!ec)
            {
                std::make_shared<GateClient>(std::move(socket))->start();
            }
            do_accept();
        });
}