#include <boost/asio.hpp>
#include <iostream>
#include "asio/multicast/receiver.cpp"
constexpr short multicast_port = 30001;
class receiver
{
  private:
    boost::asio::ip::udp::socket socket_;
    boost::asio::ip::udp::endpoint sender_endpoint_;
    std::array<char, 1024> data_;
    void do_receive()
    {
        socket_.async_receive_from(
            boost::asio::buffer(data_), sender_endpoint_, [this](boost::system::error_code &ec, std::size_t length) {
                if (!ec)
                {
                    /* code */
                    std::cout.write(data_.data(), length);
                    std::cout << std::endl;
                    do_receive();
                }
            });
    }

  public:
    receiver(boost::asio::io_context &io_context,
             const boost::asio::ip::address &listen_address,
             const boost::asio::ip::address &multicast_address) : socket_(io_context)
    {
        boost::asio::ip::udp::endpoint listen_endpoint(listen_address, multicast_port);
        socket_.open(listen_endpoint.protocol());
        socket_.set_option(boost::asio::ip::udp::socket::reuse_address(true));
        socket_.bind(listen_endpoint);
        socket_.set_option(boost::asio::ip::multicast::join_group(multicast_address));
        do_receive();
    }
    ~receiver();
};