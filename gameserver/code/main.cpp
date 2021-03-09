#include "ext_head.h"
#include "game_server_impl.h"

int main()
{
    GameServerImpl server;
    printf("gameserver begin start --------------------------\n");

    // 初始化
    if (0 != server.init())
    {
        printf("server init failed\n");
        return 1;
    }
    printf("server init succ\n");

    // 启动
    if (0 != server.start())
    {
        printf("server start failed\n");
        return 1;
    }

    // 循环running
    if (0 != server.run())
    {
        printf("server run failed\n");
        return 1;
    }

    // 关闭
    if (0 != server.stop())
    {
        printf("server stop failed\n");
        return 1;
    }

    printf("server stop succ ------------------------------\n");
    return 0;
}
