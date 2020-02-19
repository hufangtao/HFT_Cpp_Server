
#ifndef SERVER_H
#define SERVER_H
class Server
{
    public:
        Server(boost::asio::io_service& io_service, short port);
        ~Server() {}

    private:
        void do_accept();

        tcp::acceptor acceptor_;
        tcp::socket socket_;
};
#endif

