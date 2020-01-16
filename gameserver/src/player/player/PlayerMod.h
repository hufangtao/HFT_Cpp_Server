#ifndef PLAYERMOD_H
#define PLAYERMOD_H
#include "player/Mod.h"

class PlayerMod: public Mod
{
private:
    /* data */
public:
    PlayerMod(/* args */);
    ~PlayerMod();

    void handle_c2s(int pmd, int param, google::protobuf::Message* msg);
};

#endif