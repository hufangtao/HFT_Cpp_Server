#include "PlayerMod.h"
#include "common/proto/PlayerPmd.pb.h"

PlayerMod::PlayerMod(/* args */)
{
}

PlayerMod::~PlayerMod()
{
}

void PlayerMod::handle_c2s(int pmd, int param, google::protobuf::Message *message)
{
    {
        int pmd1, param1;
        ProtoUtils::msgDecode->getCmdParamByMessageName("SelfInfoPlayerPmd_C2S", pmd1, param1);
        std::cout << "pmd" << pmd1 << "param:" << param1 << std::endl;
        if (pmd == pmd1 && param == param1)
        {
            PlatPmd::SelfInfoPlayerPmd_C2S *netPackage = dynamic_cast<PlatPmd::SelfInfoPlayerPmd_C2S *>(message);
            std::cout << "in PlayerMod handle c2s get selfInfo" << std::endl;
            // handle(netPackage);
        }
    }

    {
        int pmd1, param1;
        ProtoUtils::msgDecode->getCmdParamByMessageName("NetPackageNullPmd_C2S", pmd1, param1);
        std::cout << "pmd" << pmd1 << "param:" << param1 << std::endl;
        if (pmd == pmd1 && param == param1)
        {
            PlatPmd::NetPackageNullPmd_C2S *netPackage = dynamic_cast<PlatPmd::NetPackageNullPmd_C2S *>(message);
            std::cout << "in PlayerMod handle c2s get netPackage" << std::endl;
            // handle(netPackage);
        }
    }
}