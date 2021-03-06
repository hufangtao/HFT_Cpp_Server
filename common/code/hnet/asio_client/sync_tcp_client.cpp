#include "sync_tcp_client.h"

SyncTcpClient::SyncTcpClient(asio::io_context& io, std::string host, std::string port):
	resolver_(io), socket_(io), host_(host), port_(port)
{

}

SyncTcpClient::~SyncTcpClient()
{

}

void SyncTcpClient::connect()
{
	if (host_.empty())
	{
		cout << "host is empty" << endl;
		return;
	}

	tcp::resolver::results_type end_points = resolver_.resolve(tcp::v4(), host_, port_);
	cout << "endpoints size: " << end_points.size() << endl;
	boost::system::error_code ec;
	asio::connect(socket_, end_points, ec);
	if (ec)
	{
		cout << "connect error, message:" << ec.message() << endl;
		return;
	}

	printf("connect success");
}

int SyncTcpClient::syncRead()
{
	while(true)
	{
		char buff[128];

		system::error_code error;
		size_t len = socket_.read_some(asio::buffer(buff), error);
		if (error == asio::error::eof)
		{
			break;
		}
		else if (error)
		{
			cout << "read exception" << endl;
			break;
		}
		std::cout.write(buff, len);
	}

	return 0;
}

int SyncTcpClient::syncSend(string msg)
{
	size_t len = socket_.send(asio::buffer(msg));
	printf("send size=%ld succ len=%zu\n", msg.length(), len);

	return 0;
}
