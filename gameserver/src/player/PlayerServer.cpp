#include "PlayerServer.h"

PlayerServer::PlayerServer(std::shared_ptr<GateClient> gateClient):gateClient_(gateClient)
{
    Mod* playerMod = new PlayerMod();
    ModList.push_back(playerMod);
}

PlayerServer::~PlayerServer()
{
}

void PlayerServer::handle_c2s(int pmd, int param, google::protobuf::Message *msg)
{
    for(int i=0;i<ModList.size();i++){
        ModList.at(i)->handle_c2s(pmd, param, msg);
    }
}