#include "config.h"

config::config(/* args */)
{

    for (auto file : CONFIG_FILE)
    {
        std::cout << "what" << file << std::endl;
    }
}

config::~config()
{
}
