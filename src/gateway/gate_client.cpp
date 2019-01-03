#include "gate_client.h"

gate_client::gate_client(tcp::socket socket) : socket_(std::move(socket))
{
}
void gate_client::start()
{
    // do_read_header();开始处理消息
}