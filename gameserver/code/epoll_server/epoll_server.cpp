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
    close(listen_fd_);
}

int EpollServer::doCreateEpoll()
{
    int fd = epoll_create(EPOLL_SIZE);
    if (fd == -1)
    {
        printf("create epoll fd error\n");
        return -1;
    }

    printf("create epoll fd=%d\n", fd);
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

    printf("bind on port=%d\n", port);
    return 0;
}

int EpollServer::startListen()
{
    if (0 == listen_fd_)
    {
        printf("listen_fd error\n");
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
        printf("epoll add listen_fd error\n");
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
                printf("epoll error\n");
                continue;
            }

            // 如果是listen_fd过来的消息
            if (listen_fd_ == events[idx].data.fd)
            {
                acceptConnection();
                continue;
            }
            else
            {
                acceptData(events[idx].data.fd);
                continue;
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
                printf("accept error\n");
                break;
            }
        }

        char host_buf[NI_MAXHOST], port_buf[NI_MAXSERV];
        if (0 != getnameinfo(&in_addr, in_len, host_buf, sizeof(host_buf), port_buf, sizeof(host_buf), NI_NUMERICHOST | NI_NUMERICSERV))
        {
            break;
        }

        printf("accepted connection on descriptor %d (host:%s, port=%s)\n", socket_fd, host_buf, port_buf);

        // 将接收的new connection加入到epoll监听中
        epoll_event socket_event;
        socket_event.data.fd = socket_fd;
        socket_event.events = EPOLLIN | EPOLLET;
        if (-1 == epoll_ctl(epoll_fd_, EPOLL_CTL_ADD, socket_fd, &socket_event))
        {
            printf("epoll ctl error\n");
            break;
        }
    }

    return 0;
}

int EpollServer::acceptData(int read_fd)
{
    int done = 0;
    while(true)
    {
        char buf[128];

        int size = read(read_fd, buf, sizeof(buf));
        if (size == -1)
        {
            if (errno != EAGAIN)
            {
                printf("read error\n");
                done = 1;
            }
            break;
        }

        if (size == 0)
        {
            // EOF，远程已经关闭连接
            done = 1;
            break;
        }

        // 标准输出
        if (-1 == write(1, buf, size))
        {
            printf("write error\n");
            break;
        }

        if (done)
        {
            printf("close connection on fd %d\n", read_fd);
            close(read_fd);
        }
    }
    return 0;
}

