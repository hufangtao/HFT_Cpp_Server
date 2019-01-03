#include "log.h"


log::log(/* args */)
{
}

log::~log()
{
}
std::list<std::string> log::logList;

void log::msg(logType type, std::string msg)
{
    // std::stringstream msgstream;
    // fun(msgstream, __VA_ARGS__);
    // std::string msg = "";
    // msgstream >> msg;

    std::string log = "";
    std::string logType = getLogType(type);
    log += logType;
    std::string time = getTime();
    log += time;
    log += ": ";
    log += msg;
    logList.push_back(log);

    writeLog();
}

/**
 * 每次记录log的时候，调用writelog，确保list中的所有msg输出到ostream
*/
void log::writeLog()
{
    while (!logList.empty())
    {
        std::string msg = logList.front();
        logList.pop_front();
        getStream() << msg;
    }
}

/**
 * 获取输出流
 * 根据输出流来确定日志打印位置：文件、屏幕
*/
std::ostream &log::getStream()
{
#ifdef RUN_LIVE
#else
    return std::cout;
#endif
}

/**
 * 获取当前打印log的时间
*/
std::string log::getTime()
{
    time_t timep;
    time(&timep);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "[%Y-%m-%d %H:%M:%S]", localtime(&timep));
    return tmp;
}

/**
 * 根据type获取log的类型字符串
 * @param type logType类型
*/
std::string log::getLogType(logType type)
{
    std::string msgType;
    switch (type)
    {
    case DEBUG_MSG:
        msgType = "[DEBUG]";
        break;
    case INFO_MSG:
        msgType = "[INFO]";
        break;
    case ERROR_MSG:
        msgType = "[ERROR]";
        break;
    case WARN_MSG:
        msgType = "[WARN]";
        break;
    default:
        msgType = "[OTHER]";
        break;
    }
    return msgType;
}