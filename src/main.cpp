#include <iostream>
#include "gateway/GatewayTcpServer.h"

#include "serverutils/common.h"

int main(int argc, char *argv[])
{
    try
    {
        // 加载一些配置文件
        DEBUG("ian a msg",23);
        boost::asio::io_context io_context;
        GatewayTcpServer::listen_tcp_port(io_context, 9001);

        io_context.run();
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
