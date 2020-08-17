#ifndef __TCP_CONNECTION_H__
#define __TCP_CONNECTION_H__

#include "ext_head.h"

using namespace boost::asio::ip;

class TcpConnection: public std::enable_shared_from_this<TcpConnection>
{
	public:
		~TcpConnection();
	
	public:
		typedef boost::shared_ptr<TcpConnection> pointer;

		static std::shared_ptr<TcpConnection> create(boost::asio::io_context& io_context);
		tcp::socket& socket();
		void start();

	private:
		TcpConnection(asio::io_context& io_context);
		void handle_write(const system::error_code& error, size_t bytes);
	
	private:
		tcp::socket socket_;
		std::string message_;
};

#endif

