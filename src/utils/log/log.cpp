#include "log.h"

log::log(/* args */)
{
}

log::~log()
{
}

void log::msg(logType type, std::string msg)
{
}

/**
 * 获取输出流
 * 根据输出流来确定日志打印位置：文件、屏幕
*/
std::ostream &log::getStream()
{
    return std::cout;
}
