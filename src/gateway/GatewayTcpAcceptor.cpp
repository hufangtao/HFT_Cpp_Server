#include "GatewayTcpAcceptor.h"
#include "player/PlayerServer.h"

GatewayTcpAcceptor::GatewayTcpAcceptor(
    boost::asio::io_context &io_context,
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
                auto gateClient = std::make_shared<GateClient>(std::move(socket));
                auto playerServer = std::make_shared<PlayerServer>(gateClient);
                gateClient->set_player_server(playerServer);
                gateClient->start();
            }
            do_accept();
        });
}