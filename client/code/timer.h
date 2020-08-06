#ifndef __TIMER_H__
#define __TIMER_H__

#include "ext_head.h"

class Timer
{
    public:
        Timer(asio::io_context& io);
        ~Timer();

        void print1();
		void print2();

    private:
		// asio::strand<boost::asio::io_context::executor_type> strand_;
		asio::steady_timer timer1_;
		asio::steady_timer timer2_;
		int counter_;
};

#endif
