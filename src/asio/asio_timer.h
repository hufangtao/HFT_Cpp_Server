#ifndef ASIO_TIMER_H
#define ASIO_TIMER_H
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <iostream>
class Asio_Timer
{
public:
  Asio_Timer();
  void Run();

private:
  boost::asio::io_service io_service;
  boost::asio::deadline_timer timer;
  boost::asio::ip::tcp::resolver resolver;
  boost::asio::ip::tcp::socket sock;
  boost::array<char, 4096> buffer;
};
void handler(const boost::system::error_code &ec);
#endif