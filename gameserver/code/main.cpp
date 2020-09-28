#include "ext_head.h"
#include "player.h"
#include "tcp_server.h"
#include "epoll_server/epoll_server.h"

int main()
{
    printf("create epoll server b\n");
    EpollServer epoll_server;
    printf("create epoll server\n");
    if (0 != epoll_server.bindPort(9999))
    {
        return 0;
    }

    epoll_server.startListen();
    epoll_server.startAccept();
    return 0;
}
