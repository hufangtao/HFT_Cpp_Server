#ifndef __GAME_SERVER_IMPL_H__
#define __GAME_SERVER_IMPL_H__

#include "global.h"

class GameServerImpl
{
    public:
        GameServerImpl();
        ~GameServerImpl();

    public:
        int init();
        int start();
        int run();
        int stop();
};


#endif // __GAME_SERVER_IMPL_H__