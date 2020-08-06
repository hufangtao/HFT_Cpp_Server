#ifndef __TCP_SERVER_H__
#define __TCP_SERVER_H__

#include "ext_head.h"

class TcpServer
{
	public:
		TcpServer(asio::io_context& io_context);
		~TcpServer();

	public:
		void start_accept();

	public:
		asio::io_context io_context_;
		tcp::acceptor acceptor_;

	private:
		
};

#endif

