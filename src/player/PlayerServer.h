#ifndef PLAYERSERVER_H
#define PLAYERSERVER_H

#include "player/PlayerMod.h"
#include "gateway/GateClient.h"

#include <vector>

/** 
 * 玩家服务
 * 注册多个模块，房间模块，物品模块等
 * 将消息分发给每个Mod，由Mod统一处理
*/
class PlayerServer
{
  private:
    /* data */
    std::vector<Mod*> ModList;
    std::weak_ptr<GateClient> gateClient_;
  public:
    PlayerServer(std::shared_ptr<GateClient> gateClient);
    ~PlayerServer();

    void handle_c2s(int pmd, int param, google::protobuf::Message *msg);
    void set_gateClient(std::shared_ptr<GateClient> gateClient);
};

#endif