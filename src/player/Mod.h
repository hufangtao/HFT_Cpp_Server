#ifndef MOD_H
#define MOD_H

#include "common/utils/ProtoUtils.h"
#include <google/protobuf/message.h>

class Mod
{
private:
    /* data */
public:
    Mod(/* args */);
    ~Mod();

    /**
     * 自类根据想要监听事件类型，从MessageSerializer中获取pmd和param；
     * 如果不是该pmd和param则return，否则处理为该类型
    */
    virtual void handle_c2s(int pmd, int param, google::protobuf::Message* msg);
};

#endif