#include "log.h"


log::log(/* args */)
{
}

log::~log()
{
}
std::list<std::string> log::logList;

void log::addMsg(std::string msg)
{
    logList.push_back(msg);
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
    std::stringstream ss;
    
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


void printLog(std::stringstream &ss)
{
    ss << std::endl;
}

template <class T, class... Args>
void printLog(std::stringstream &ss, T head, Args... rest)
{
    ss << head;
    printLog(ss, rest...);
}

template <class... T>
void LOG(std::string type, std::string date, std::string time, std::string file, std::string func, int line, T... args)
{
    std::stringstream ss;
    ss << "[" << type << "]" << date << "-" << time << "-" << file << "-" << func << "-line" << line << ":" << std::endl;
    printLog(ss, args...);
    log::addMsg(ss.str());
}