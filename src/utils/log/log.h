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


void printLog(std::stringstream &ss);

template <class T, class... Args>
void printLog(std::stringstream &ss, T head, Args... rest);

template <class... T>
void LOG(std::string type, std::string date, std::string time, std::string file, std::string func, int line, T... args);

#define DEBUG(MSG...) LOG("DEBUG", __DATE__, __TIME__, __FILE__, __FUNCTION__, __LINE__, ##MSG)
#define INFO(MSG...) LOG("INFO", __DATE__, __TIME__, __FILE__, __FUNCTION__, __LINE__, ##MSG)
#define WARN(MSG...) LOG("WARN", __DATE__, __TIME__, __FILE__, __FUNCTION__, __LINE__, ##MSG)
#define ERROR(MSG...) LOG("ERROR", __DATE__, __TIME__, __FILE__, __FUNCTION__, __LINE__, ##MSG)


#endif
