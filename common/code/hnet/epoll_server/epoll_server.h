
#ifndef __EPOLL_SERVER__
#define __EPOLL_SERVER__

#include "ext_head.h"

class EpollServer
{
    public:
        EpollServer();
        ~EpollServer();

    public:
        int bindPort(uint port);
        int startListen();
        int startAccept();

    private:
        int doCreateEpoll();
        int makeSocketNonBlocking(int sfd);
        int acceptConnection();
        int acceptData(int read_fd);

    private:
        enum {MAX_EVENTS_SIZE = 1024, EPOLL_SIZE = 20000};
        int epoll_fd_;
        int listen_fd_;
};

#endif // __EPOLL_SERVER__
