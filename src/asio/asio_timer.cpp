#include "asio_timer.h"
Asio_Timer::Asio_Timer() : timer(io_service, boost::posix_time::seconds(5)) {
}

void Asio_Timer::Run(){
    timer.async_wait(handler);
    io_service.run();
}
