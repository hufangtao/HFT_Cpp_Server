#ifndef __SYNC_TCP_CLIENT_H__
#define __SYNC_TCP_CLIENT_H__

#include "ext_head.h"
using namespace boost::asio::ip;
class SyncTcpClient
{
	public:
		SyncTcpClient(asio::io_context& io, std::string host, std::string port);
		~SyncTcpClient();

	public:
		void connect();
		int syncRead();
		int syncSend(string msg);

	private:
		tcp::resolver resolver_;
		tcp::socket socket_;
		std::string host_;
		std::string port_;
};

#endif

