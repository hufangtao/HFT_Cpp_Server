#include "timer.h"

Timer::Timer(asio::io_context& io): 
	// strand_(asio::make_strand(io)),
	timer1_(io, asio::chrono::seconds(1)),
	timer2_(io, asio::chrono::seconds(1)),
	counter_(0)
{
    timer1_.async_wait(std::bind(&Timer::print1, this));
    timer2_.async_wait(std::bind(&Timer::print2, this));
}

Timer::~Timer()
{
    cout << "ToTal Count: " << counter_ << endl;
}

void Timer::print1()
{
    if (counter_ < 10)
    {
        cout << counter_ << endl;
        ++counter_;
        timer1_.expires_at(timer1_.expiry() + asio::chrono::seconds(1));
        timer1_.async_wait(std::bind(&Timer::print1, this));
    }
}

void Timer::print2()
{
    if (counter_ < 10)
    {
        cout << counter_ << endl;
        ++counter_;
        timer2_.expires_at(timer2_.expiry() + asio::chrono::seconds(1));
        timer2_.async_wait(std::bind(&Timer::print2, this));
    }
}
