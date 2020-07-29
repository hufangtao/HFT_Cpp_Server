#include "timer.h"

Timer::Timer(asio::io_context& io): timer_(io, asio::chrono::seconds(1)), counter_(0)
{
    timer_.async_wait(std::bind(&Timer::print, this));
}

Timer::~Timer()
{
    cout << "ToTal Count: " << counter_ << endl;
}

void Timer::print()
{
    if (counter_ < 5)
    {
        cout << counter_ << endl;
        ++counter_;
        timer_.expires_at(timer_.expiry() + asio::chrono::seconds(1));
        timer_.async_wait(std::bind(&Timer::print, this));
    }
}

