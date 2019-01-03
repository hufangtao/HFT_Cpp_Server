#include "gateway_tcp_acceptor.h"

gateway_tcp_acceptor::gateway_tcp_acceptor(boost::asio::io_context &io_context,
                         const tcp::endpoint &endpoint) : acceptor_(io_context)
{
    do_accept();
}

void gateway_tcp_acceptor::do_accept()
{
    acceptor_.async_accept(
        [this](boost::system::error_code ec, tcp::socket socket) {
            if (!ec)
            {
                std::make_shared<gate_client>(std::move(socket))->start();
            }
            do_accept();
        });
}