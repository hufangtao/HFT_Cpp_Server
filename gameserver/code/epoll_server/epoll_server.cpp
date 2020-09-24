#include "epoll_server.h"
#include <sys/epoll.h>
#include <fcntl.h>

EpollServer::EpollServer()
    : epoll_fd_(doCreateEpoll())
{
}

EpollServer::~EpollServer()
{

}

int EpollServer::doCreateEpoll()
{
    int fd = epoll_create(EPOLL_SIZE);

    // 创建成功
    if (fd != -1)
    {
        ::fcntl(fd, F_SETFD, FD_CLOEXEC);
    }

    return fd;
}

