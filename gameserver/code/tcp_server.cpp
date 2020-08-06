#include "tcp_server.h"

TcpServer::TcpServer(asio::io_context& io_context):
	io_context_(io_context),
	acceptor_(io_context, tcp::endpoint(tcp::v4(), 13))
{
	start_accept();
}

TcpServer::~TcpServer()
{

}

void TcpServer::start_accept()
{
	tcp::connection::pointer new_connection = tcp::connection::create(io_context_);

	accpetor_.async_accpet(new_connection->socket(), 
				std::bind(&TcpServer::handle_accept, this, new_connection, boost::asio::placeholders::error));
}

void TcpServer::handle_accept(tcp::connection::pointer new_connection, const boost::system::error_code& error)
{
	if (!error)
	{
		new_connection->start();
	}

	start_accept();
}

