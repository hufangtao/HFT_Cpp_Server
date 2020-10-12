#include "ext_head.h"
#include "player.h"
#include "hnet/epoll_server/epoll_server.h"

int main()
{
    EpollServer epoll_server;
    if (0 != epoll_server.bindPort(9999))
    {
        return 0;
    }

    epoll_server.startListen();
    epoll_server.startAccept();
    return 0;
}
