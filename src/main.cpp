#include <iostream>
#include "gateway/gateway_tcp_server.h"

#include "utils/common.h"

int main(int argc, char *argv[])
{
    try
    {
        // 加载一些配置文件
        DEBUG("ianamsg");
        // boost::asio::io_context io_context;
        // gateway_tcp_server tcp_server;
        // for (int i = 1; i < argc; ++i)
        // {
        //     tcp_server.listen_tcp_port(io_context, std::atoi(argv[i]));
        // }
        // io_context.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}