#include <iostream>
#include <map>
#include "player.h"
using namespace std;

const char* getStringPtr()
{
    string str("test");
    cout << str << endl;
    cout << str.c_str() << endl;
    return str.c_str();
}

int main()
{
    map<int, int> test_map;
    for (auto iter = test_map.begin(); iter != test_map.end(); ++iter)
    {
    }

    const char* a = getStringPtr();
    cout << *a << *(a+2) << endl;
    return 0;
}
