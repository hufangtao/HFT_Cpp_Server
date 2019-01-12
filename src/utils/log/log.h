#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <sstream>
#include <list>
#include <time.h>
/**
 * 简易输出log
 * 记录log
*/

class log
{
  private:
    static std::list<std::string> logList;

  public:
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

    static void writeLog();
    static std::string getTime();
    static std::string getLogType(logType type);
    static void addMsg(std::string msg);
    static std::ostream &getStream();
};

#endif
