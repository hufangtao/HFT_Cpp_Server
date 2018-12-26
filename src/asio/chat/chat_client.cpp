#include "chat_client.h"

chat_client::chat_client(boost::asio::io_context &io_context,
                         const tcp::resolver::results_type &endpoints) : io_context_(io_context), socket_(io_context)
{
    do_connect(endpoints);
}

chat_client::~chat_client()
{
}

void chat_client::write(const chat_message &msg){

}
void chat_client::close(){

}
void chat_client::do_connect(const tcp::resolver::results_type &endpoints){
    boost::asio::async_connect(socket_, endpoints,
    [this](boost::system::error_code ec, tcp::endpoint){
        if(!ec){
            do_read_hander();
        }
    });
}
void chat_client::do_read_header(){

}
void chat_client::do_read_body(){

}
void chat_client::do_write(){

}