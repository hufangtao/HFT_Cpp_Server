#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <string>
#include <map>

#include "utils/common.h"

static const std::string CONFIG_FILE[] = {
    "../../../etc/config/server.conf"};
/**
 * 负责加载配置文件
 * 供其他模块访问配置
*/
class config
{
private:
    std::map<std::string, std::string> config_map;

public:
    config();
    ~config();
};
#endif