#ifndef PLAYERSERVER_H
#define PLAYERSERVER_H

/** 
 * 玩家服务
 * 注册多个模块，房间模块，物品模块等
 * 将消息分发给每个Mod，由Mod统一处理
*/
class PlayerServer
{
private:
  /* data */
public:
  PlayerServer(/* args */);
  ~PlayerServer();
};

#endif