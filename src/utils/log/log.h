#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <list>
/**
 * 简易输出log
 * 记录log
*/
#define DEBUG(MSG) \
    log::          \
        msg(DEBUG_MSG, MSG)
#define INFO(MSG) \
    log::         \
        msg(INFO_MSG, MSG)
#define WARN(MSG) \
    log::         \
        msg(WARN_MSG, MSG)
#define ERROR(MSG) \
    log::          \
        msg(ERROR_MSG, MSG)
class log
{
  private:
    std::list<std::string> logList;
    enum logType
    {
        DEBUG_MSG = 1,
        INFO_MSG,
        WARN_MSG,
        ERROR_MSG
    };

  public:
    log();
    ~log();

    static std::ostream& getStream();
    static void msg(logType type, std::string msg);
};
#endif