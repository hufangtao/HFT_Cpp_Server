#include "asio_timer.h"

void handler(const boost::system::error_code &ec){
    std::cout<<"5 s."<<std::endl;
}

Asio_Timer::Asio_Timer() : 
    timer(io_service, boost::posix_time::seconds(5)), resolver(io_service),
    sock(io_service){
}

void Asio_Timer::Run(){
    timer.async_wait(handler);
    io_service.run();
}
