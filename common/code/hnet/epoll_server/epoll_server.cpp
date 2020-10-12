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
    int fd = epoll_create1(0);
    if (fd == -1)
    {
        printf("create epoll fd error\n");
        return -1;
    }

    printf("create epoll epoll_fd=%d\n", fd);
    return fd;
}

int EpollServer::makeSocketNonBlocking(int sfd)
{
	int flags, s;
 
	flags = fcntl(sfd, F_GETFL, 0);
	if (flags == -1)
	{
		perror("fcntl");
		return -1;
	}
 
	flags |= O_NONBLOCK;
	s = fcntl(sfd, F_SETFL, flags);
	if (s == -1)
	{
		perror("fcntl");
		return -1;
	}
 
	return 0;
}

int EpollServer::bindPort(uint port)
{
    // 创建监听fd
    listen_fd_ = socket(AF_INET, SOCK_STREAM, 0);
    makeSocketNonBlocking(listen_fd_);
    printf("create listen fd=%d\n", listen_fd_);

    // 绑定监听fd
    sockaddr_in my_addr;
    bzero(&my_addr, sizeof(my_addr));
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(port);
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    int ret_code = ::bind(listen_fd_, (struct sockaddr *)&my_addr, sizeof(my_addr));
    if (0 != ret_code)
    {
        printf("bind error, ret_code=%d\n", ret_code);
        return -1;
    }

    printf("bind on port=%d, ret_code=%d\n", port, ret_code);
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
    int ret_code = listen(listen_fd_, 10);
    if (ret_code != 0)
    {
        printf("listen error retcode=%d\n", ret_code);
        return -1;
    }

    // 添加listen_fd的监听
    epoll_event event;  // 需要监听的事件
    event.data.fd = listen_fd_; // 监听套接字
    event.events = EPOLLIN;     // 监听读事件
    ret_code = epoll_ctl(epoll_fd_, EPOLL_CTL_ADD, listen_fd_, &event);
    if (ret_code != 0)
    {
        printf("epoll add listen_fd error, ret_code=%d\n", ret_code);
        return -1;
    }

    printf("start listen on listen_fd=%d\n", listen_fd_);
    return 0;
}

int EpollServer::startAccept()
{
    if (listen_fd_ == 0 || epoll_fd_ == 0)
    {
        printf("accept fd error, listen_fd=%d, epoll_fd=%d\n", listen_fd_, epoll_fd_);
        return -1;
    }

    epoll_event events[MAX_EVENTS_SIZE];
    bzero(events, sizeof(*events));

    while(true)
    {
        int valid_events_num = epoll_wait(epoll_fd_, events, MAX_EVENTS_SIZE, -1);

        printf("epoll wait valid_events_num=%d\n", valid_events_num);
        for (int idx = 0; idx < valid_events_num; ++idx)
        {
            printf("deal event idx=%d, event_fd=%d\n", idx, events[idx].data.fd);
            if ((events[idx].events & EPOLLERR) || 
                (events[idx].events & EPOLLHUP) || 
                (!(events[idx].events & EPOLLIN)))
            {
                printf("epoll error\n");
                close(events[idx].data.fd);
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
    printf("start accept connection\n");
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
                printf("already accept all connection\n");
                break;
            }
            else
            {
                printf("accept error\n");
                break;
            }
        }

        printf("listen_fd=%d accepted connection on descriptor %d\n", listen_fd_, socket_fd);
        // 将接收的new connection加入到epoll监听中
        epoll_event socket_event;
        socket_event.data.fd = socket_fd;
        socket_event.events = EPOLLIN | EPOLLET;
        makeSocketNonBlocking(socket_fd);
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
    printf("strat accept data\n");
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
        printf("fd=%d say: %s\n", read_fd, buf);

        if (done)
        {
            printf("close connection on fd %d\n", read_fd);
            close(read_fd);
            break;
        }
    }
    return 0;
}

