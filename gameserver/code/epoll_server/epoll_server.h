#ifndef __EPOLL_SERVER__
#define __EPOLL_SERVER__

class EpollServer
{
    public:
        EpollServer();
        ~EpollServer();

    public:
        int32_t doCreateEpoll();

    private:
        enum {EPOLL_SIZE = 20000};
        int32_t epoll_fd_;
};

// __EPOLL_SERVER__
