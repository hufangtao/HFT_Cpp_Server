#include "ext_head.h"
#include "player.h"
#include "hnet/epoll_server/epoll_server.h"

enum MissionFinishWay
{
    NONE = 0,
    AUTO = 1,
    AVATAR = 3
};

int main()
{
    int a = 2;
    cout << MissionFinishWay(a) << endl;
    cout << static_cast<MissionFinishWay>(5) << endl;
    return 0;
}
