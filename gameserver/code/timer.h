#ifndef __TIMER_H__
#define __TIMER_H__

#include "ext_head.h"

class Timer
{
    public:
        Timer(asio::io_context& io);
        ~Timer();

        void print();

    private:
        asio::steady_timer timer_;
        int counter_;
};

#endif
