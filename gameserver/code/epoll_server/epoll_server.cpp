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

int EpollServer::startAccept()
{
    if (listen_fd_ == 0 || epoll_fd_ == 0)
    {
        return -1;
    }

    epoll_event events[MAX_EVENTS_SIZE];
    bzero(events, sizeof(*events));

    while(true)
    {
        int valid_events_num = epoll_wait(epoll_fd_, events, MAX_EVENTS_SIZE, -1);

        for (int idx = 0; idx < valid_events_num; ++idx)
        {
            if ((events[idx].events & EPOLLERR) || 
                (events[idx].events & EPOLLHUP) || 
                !(events[idx].events & EPOLLIN))
            {
                printf("epoll error");
                continue;
            }

            // 如果是listen_fd过来的消息
            if (listen_fd_ == events[idx].data.fd)
            {

            }
        }
    }

    return 0;
}

int EpollServer::acceptConnection()
{
    while(true)
    {
        sockaddr in_addr;
        socklen_t in_len;

        int socket_fd = accept(listen_fd_, &in_addr, &in_len);
        if (socket_fd == -1)
        {
            if ((errno == EAGAIN)||(errno == EWOULDBLOCK))
            {
                // 已经处理了所有连接
                break;
            }
            else
            {
                printf("");
                break;
            }
        }
    }
    return 0;
}

int EpollServer::acceptData()
{
    return 0;
}

