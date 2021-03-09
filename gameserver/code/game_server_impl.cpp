#include "game_server_impl.h"

GameServerImpl::GameServerImpl(/* args */)
{
}

GameServerImpl::~GameServerImpl()
{
}

int GameServerImpl::init()
{
    // 初始化
    if (0 != Global::async_http_client_mgr.init(1))
    {
        printf("init async http client error\n");
        return -1;
    }
    printf("init async http client succ\n");
    

    return 0;
}

int GameServerImpl::start()
{
    // 启动
    if (0 != Global::async_http_client_mgr.start())
    {
        printf("start async http client mgr error\n");
        return -1;
    }
    printf("start async http client mgr succ\n");

    Global::async_http_client_mgr.addRequest("https://www.baidu.com");
    return 0;
}

int GameServerImpl::run()
{
    while (0 == Global::shutdown)
    {
        printf("running\n");
        sleep(2);
    }
    
    return 0;
}

int GameServerImpl::stop()
{
    // 停止退出
    if (0 != Global::async_http_client_mgr.stop())
    {
        printf("stop async http client mgr error\n");
    }

    return 0;
}