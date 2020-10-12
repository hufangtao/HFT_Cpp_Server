#ifndef __TCP_SERVER_H__
#define __TCP_SERVER_H__

#include "ext_head.h"
#include "tcp_connection.h"

using namespace boost::asio::ip;

class TcpServer
{
	public:
		TcpServer(asio::io_context& io_context);
		~TcpServer();

	public:
		void start_accept();
		void handle_accept(std::shared_ptr<TcpConnection> connection_ptr, const boost::system::error_code& error);

	private:
		asio::io_context& io_context_;
		tcp::acceptor acceptor_;
};

#endif

