#include "tcp_connection.h"

TcpConnection::TcpConnection(asio::io_context& io_context): socket_(io_context)
{
	
}

TcpConnection::~TcpConnection()
{

}

std::shared_ptr<TcpConnection> TcpConnection::create(asio::io_context& io_context)
{
	return std::shared_ptr<TcpConnection>(new TcpConnection(io_context));
}

tcp::socket& TcpConnection::socket()
{
	return socket_;
}

void TcpConnection::start()
{
	message_ = "testeeee";

	asio::async_write(
				socket_, 
				asio::buffer(message_), 
				boost::bind(
						&TcpConnection::handle_write, 
						shared_from_this(),
						asio::placeholders::error, 
						asio::placeholders::bytes_transferred
				)
	);
}

void TcpConnection::handle_write(const system::error_code&, size_t)
{

}

