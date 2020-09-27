#include "ext_head.h"
#include "player.h"
#include "tcp_server.h"
#include "epoll_server/epoll_server.h"

int main()
{
    EpollServer epoll_server;
    epoll_server.bindPort(9999);
    epoll_server.startListen();
    epoll_server.startAccept();
    return 0;
}

