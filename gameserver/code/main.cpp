#include "ext_head.h"
#include "player.h"
#include "tcp_server.h"
#include "epoll_server/epoll_server.h"

int main()
{
    printf("create epoll server b\n");
    EpollServer epoll_server;
    printf("create epoll server\n");
    epoll_server.bindPort(9999);
    epoll_server.startAccept();
    epoll_server.startListen();
    return 0;
}
