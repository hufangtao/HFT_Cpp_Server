#ifndef HLOG_H
#define HLOG_H

#include <sstream>
#include <iostream>
#include "log.h"

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

#define DEBUG(MSG...) LOG("DEBUG", __DATE__, __TIME__, __FILE__, __FUNCTION__, __LINE__, ##MSG)
#define INFO(MSG...) LOG("INFO", __DATE__, __TIME__, __FILE__, __FUNCTION__, __LINE__, ##MSG)
#define WARN(MSG...) LOG("WARN", __DATE__, __TIME__, __FILE__, __FUNCTION__, __LINE__, ##MSG)
#define ERROR(MSG...) LOG("ERROR", __DATE__, __TIME__, __FILE__, __FUNCTION__, __LINE__, ##MSG)

#endif