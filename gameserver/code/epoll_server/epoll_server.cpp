#include "epoll_server.h"
#include <sys/epoll.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

EpollServer::EpollServer()
    : epoll_fd_(doCreateEpoll()), listen_fd_(0)
{
}

EpollServer::~EpollServer()
{

}

int EpollServer::doCreateEpoll()
{
    int fd = epoll_create(EPOLL_SIZE);

    // 创建成功
    if (fd == -1)
    {
        printf("create epoll fd error");
        return -1;
    }

    return fd;
}

int EpollServer::bindPort(uint port)
{
    // 创建监听fd
    listen_fd_ = socket(AF_INET, SOCK_STREAM, 0);

    // 绑定监听fd
    sockaddr_in my_addr;
    bzero(&my_addr, sizeof(my_addr));
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(port);
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    ::bind(listen_fd_, (struct sockaddr *)&my_addr, sizeof(my_addr));

    return 0;
}

int EpollServer::startListen()
{
    if (0 == listen_fd_)
    {
        printf("listen_fd error");
        return -1;
    }

    // 开始监听
    listen(listen_fd_, 10);

    // 添加listen_fd的监听
    epoll_event event;  // 需要监听的事件
    event.data.fd = listen_fd_; // 监听套接字
    event.events = EPOLLIN;     // 监听读事件
    int ret = epoll_ctl(epoll_fd_, EPOLL_CTL_ADD, listen_fd_, &event);
    if (-1 == ret)
    {
        printf("epoll add listen_fd error");
        return -1;
    }

    return 0;
}

