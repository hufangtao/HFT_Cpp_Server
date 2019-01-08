#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <list>
/**
 * 简易输出log
 * 记录log
*/
void printLog(std::string &msg){
    log::msg(msg);
}
template <class T, class ...Args>
void printLog(std::string &msg, T head, Args... rest){
    printLog(msg, rest...);
}

template <class... T>
void LOG_WARN(T... args)
{
    std::string msg();
    printLog(msg, args...);
}
template <class... T>
void LOG_INFO(T... args)
{
    std::string msg();
    printLog(msg, args...);
}
template <class... T>
void LOG_ERROR(T... args)
{
    std::string msg();
    printLog(msg, args...);
}

template <class... T>
void LOG_DEBUG(std::string data, std::string time, std::string file, std::string func, int line, T... args)
{
    std::string msg();
    printLog(msg, args...);
}
#define DEBUG(MSG...) LOG_DEBUG(__DATE__, __TIME__, __FILE__, __FUNCTION__, __LINE__, ##MSG)
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

    static std::ostream &getStream();
    static void msg(logType type, const std::string date, const std::string time, const std::string file, const std::string line, const std::string func, ...);
};
#endif