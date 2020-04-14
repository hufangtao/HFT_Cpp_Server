#include "hserver_mgr.h"

HServerMgr::HServerMgr(boost::asio::io_service& io_service, short port);

int HServerMgr::init(int ip, int port)
{
    cout << "server init" << endl;
    return 0;
}

int HServerMgr::start()
{
    status_ = STATUS_START;
    // 监听协程

    // for (int idx = 0; idx < HNET_ASERVER_MAX_THREAD_NUM; ++idx)
    // {
    //     io_service_thread_group_.create_thread(boost::bind(&HServerMgr<HSession>::iosThreadHandler, this, idx));
    // }
    return 0;
}

int HServerMgr::join()
{
    io_service_thread_group_.join_all();
    return 0;
}

int HServerMgr::nonBlockStop()
{
    return 0;
}

int HServerMgr::blockStop()
{
    join();
    cout << "server stoped" <<endl;
    return 0;
}

template<typename HSession>
void HServerMgr<HSession>::iosThreadHandler(int thread_idx)
{
    // 获取
    io_service& ios = io_service_arr[thread_idx];

    // 随便设置一个定时器，防止ios没事做，导致直接退出
    deadline_timer dt(ios, posix::seconds(1));
    dt.async_wait(bind(&HServerMgr<HSession>::iosTimeoutHandler, this, boost::asio::placeholders::error, &dt));

    // 如果已经启动，则启动ios
    while(status_ == STATUS_START)
    {
        try
        {
            ios.run();
        }
        catch (std::exception& e)
        {
            cout << "catch exception " << e.what() << endl;
            continue;
        }
        break;
    }

    // 初始化完毕
    status_ = STATUS_INIT;
}

template<typename HSession>
void HServerMgr<HSession>::iosTimeoutHandler(const boost::asio::placeholders::error&, deadline_timer* dt_ptr)
{
    // 还未初始化完毕，继续计时
    if (NULL != dt_ptr && status_ == STATUS_START)
    {
        dt_ptr->expires_at(dt_ptr->expires_at() + posix_time::seconds(1));
        dt_ptr->async_wait(bind(&AserverMgr<SessionT>::iosTimeoutHandler, this, boost::asio::placeholders::error, dt_ptr));
    }
}
