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

template <typename T>
void msgString(std::stringstream &msgstream, const T &t)
{
    msgstream << t << '\n';
}

template <typename T, typename... Args>
void msgString(std::stringstream &msgstream, const T &t, Args... args)
{
    msgstream << t;
    msgString(msgstream, args...);
}

#define LOG(...)                                               \
    {                                                          \
        fprintf(stderr, "%s: Line %d:\t", __FILE__, __LINE__); \
        fprintf(stderr, __VA_ARGS__);                          \
        fprintf(stderr, "\n");                                 \
    }

#define DEBUG(...)                               \
    {                                            \
        std::stringstream __MSG_SSTREAM__;       \
        msgString(__MSG_SSTREAM__, __VA_ARGS__); \
        std::string __MSG__TEMP__;               \
        __MSG_SSTREAM__ >> __MSG__TEMP__;        \
        log::msg(log::DEBUG_MSG, __MSG__TEMP__); \
    }

#define INFO(...) \
    log::         \
        msg(log::INFO_MSG, __VA_ARGS__)
#define WARN(...) \
    log::         \
        msg(log::WARN_MSG, __VA_ARGS__)
#define ERROR(...) \
    log::          \
        msg(log::ERROR_MSG, __VA_ARGS__)
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

    static std::ostream &getStream();
    static std::string getTime();
    static std::string getLogType(logType type);
    static void msg(logType type, std::string msg);
};
#endif