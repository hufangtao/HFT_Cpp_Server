#ifndef ASIO_TIMER_H
#define ASIO_TIMER_H
#include <boost/asio.hpp>
class Asio_Timer
{
  public:
    Asio_Timer();
    void Run();

  private:
    boost::asio::io_service io_service;
    boost::asio::deadline_timer timer;
};
void handler(const boost::system::error_code &ec);
#endif