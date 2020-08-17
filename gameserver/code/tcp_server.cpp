#include "tcp_server.h"

TcpServer::TcpServer(asio::io_context& io_context):
	io_context_(io_context),
	acceptor_(io_context, tcp::endpoint(tcp::v4(), 22001))
{
	start_accept();
}

TcpServer::~TcpServer()
{

}

void TcpServer::start_accept()
{
	std::shared_ptr<TcpConnection> new_connection_ptr = TcpConnection::create(io_context_);

	acceptor_.async_accept(
				new_connection_ptr->socket(), 
				boost::bind(
						&TcpServer::handle_accept, 
						this, 
						new_connection_ptr, 
						asio::placeholders::error
				)
	);
}

void TcpServer::handle_accept(std::shared_ptr<TcpConnection> connection_ptr, const boost::system::error_code& error)
{
	if (!error)
	{
		connection_ptr->start();
	}

	start_accept();
}

