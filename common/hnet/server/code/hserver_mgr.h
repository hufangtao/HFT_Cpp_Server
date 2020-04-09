#ifndef __H_SERVER_H
#define __H_SERVER_H

#include <boost/thread/thread.hpp>

#define HNET_ASERVER_MAX_THREAD_NUM    16

namespace common
{
    namespace hnet
    {
        template<typename HSession>
        class HServerMgr
        {
            public:
                enum Status
                {
                    STATUS_UN_INIT  = 0,
                    STATUS_INIT     = 1,
                    STATUS_START    = 2,
                    STATUS_STOPPING = 3,
                    STATUS_ERROR    = 4
                }

            public:
                HServerMgr(boost::asio::io_service& io_service, short port);
                ~HServerMgr() {}

            public:
                int init(int ip, int port);
                
                int start();
                int join();
                int nonBlockStop();
                int blockStop();

            public:
                bool isRun();
                
            private:
                sig_atomic_t status_;

                io_service      io_service_arr[HNET_ASERVER_MAX_THREAD_NUM];
                thread_group    io_service_thread_group_;

                map<uint32_t, boost::shared_ptr<HSession>> session_map_;
        };
    };
};

#endif  // __H_SERVER_H
