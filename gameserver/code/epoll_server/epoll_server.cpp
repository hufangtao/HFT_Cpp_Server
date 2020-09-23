#include "epoll_server.h"
#include <sys/epoll.h>

EpollServer::EpollServer()
    : epoll_fd_(doCreateEpoll())
{

    epoll_ctl(epoll_fd_, EPOLL_CTL_ADD,);
}

EpollServer::~EpollServer()
{

}

EpollSevrer::doCreateEpoll()
{
    int fd = epoll_create(epoll_size);

    // 创建成功
    if (fd != -1)
    {
        ::fcntl(fd, F_SETFD, FD_CLOEXEC);
    }

    return fd;
}

