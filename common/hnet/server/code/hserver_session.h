#ifndef __H_SERVER_SESSION_H
#define __H_SERVER_SESSION_H

namespace common
{
    namespace hnet
    {
        using namespace boost;
        using namespace boost::asio;

        class HServerSession : public enable_shared_from_this<HServerSession>
        {
            public:
                enum Status
                {
                    STATUS_STOP = 0,
                    STATUS_INIT = 1,
                    STATUS_START = 2,
                    STATUS_STOPPING = 3
                };

            protected:
                HServerSession(io_service& ios);
                ~HServerSession();

            private:
                ip::tcp::socket     socket_;
        };
    };
};

#endif //__H_SERVER_SESSION_H