#ifndef EXAMPLEMOD_H
#define EXAMPLEMOD_H

#include "PlayerExample.h"

/** 
 * 玩家模块：样例模块
 * 负责处理：和玩家样例相关的协议
 * 调用：PlayerExample执行业务流程
*/
class ExampleMod
{
private:
  PlayerExample playerExample_;

public:
  ExampleMod(/* args */);
  ~ExampleMod();
};

#endif