#ifndef NULLMOD_H
#define NULLMOD_H

#include "player/mod.h"

void handle_c2s(PlatPmd::NetPackageNullPmd_C2S* message)
{
    std::cout<<"recv NetPackageNullPmd_C2S info"<<std::endl;
}

#endif