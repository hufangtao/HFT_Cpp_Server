#include "timer.h"

Timer::Timer(boost::asio::io_context& io): timer_(io, boost::asio::chrono::seconds(1)), counter_(0)
{
	timer_.async_wait(std::bind(&Timer::print, this));
}

Timer::~Timer()
{
	std::cout << "ToTal Count: " << counter_ << std::endl;
}

Timer::print(const boost::system::error_code& err_code)
{
	if (counter_ < 5)
	{
		std::cout << counter_ << std::endl;

		timer_.expires_at(timer_.expiry(), boost::asio::chrono::seconds(1));
		timer_.async_wait(std::bind(&Timer::print, this));
	}
}

