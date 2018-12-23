#include <iostream>
#include <time.h>
#include <boost/asio.hpp>
using boost::asio::ip::tcp;

std::string make_daytime_string(){
    using namespace std;
    time_t now = time(nullptr);
    return ctime(&now);
}

int main(){
    std::cout<<"Hello World"<<std::endl;
//    Asio_Timer timer;
//    timer.Run();
    return 0;
}

int main1() {

    
    try
    {
        /* code */
        boost::asio::io_service io_service;
        tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 13));

        for(;;){
            tcp::socket socket(io_service);
            acceptor.accept(socket);

            std::string message = make_daytime_string();

            boost::system::error_code ignore_error;
            boost::asio::write(socket, boost::asio::buffer(message), ignore_error);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}
