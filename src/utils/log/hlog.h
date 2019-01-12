#include "log.h"

std::string printLog(){
    return "";
}

template <class T, class... Args>
std::string printLog(T head, Args... rest){
    std::stringstream ss;
    std::string temp;
    ss<<head;
    ss>>temp;
    return temp + printLog(rest...);
}

template <class... T>
void LOG(std::string type,std::string date, std::string time, std::string file, std::string func, int line, T... args)
{
    std::stringstream ss;
    std::string logMsg = "";
    ss<<"["<<type<<"]"<<date<<time<<file<<func<<line;
    ss>>logMsg;
    logMsg += printLog(args...);
    log::addMsg(logMsg);
}

#define DEBUG(MSG...) LOG("DEBUG",__DATE__, __TIME__, __FILE__, __FUNCTION__, __LINE__, ##MSG)
#define INFO(MSG...) LOG("INFO",__DATE__, __TIME__, __FILE__, __FUNCTION__, __LINE__, ##MSG)
#define WARN(MSG...) LOG("WARN",__DATE__, __TIME__, __FILE__, __FUNCTION__, __LINE__, ##MSG)
#define ERROR(MSG...) LOG("ERROR",__DATE__, __TIME__, __FILE__, __FUNCTION__, __LINE__, ##MSG)