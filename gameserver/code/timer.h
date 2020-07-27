#ifndef __TIMER_H__
#define __TIMER_H__

#include "boost/asio.hpp"

class Timer
{
	public:
		Timer(boost::asio:io_context& io);
		~Timer();
	
		print(const boost:system::error_code& err_code);
	
	private:
		boost::asio::steady_timer timer_;
		int counter_;
};

#endif
