#ifndef __EPOLL_SERVER__
#define __EPOLL_SERVER__

class EpollServer
{
    public:
        EpollServer();
        ~EpollServer();

    public:
        int doCreateEpoll();

    private:
        enum {EPOLL_SIZE = 20000};
        int epoll_fd_;
};

#endif // __EPOLL_SERVER__
