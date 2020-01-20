#include <iostream>
#include <boost/lexical_cast.hpp>
#include <boost/timer.hpp>
using namespace boost;
using namespace std;

int main()
{
    timer t;
    int a = lexical_cast<int>("12");
    cout << a << endl;
    cout << "Hello World" << endl;
    try
    {
        int err = lexical_cast<int>("789edc", 4);
        cout << err << endl;
    }
    catch (const std::exception& e)
    {
        cout << e.what() << endl;
    }
    usleep(1231);
    cout << "Test:" << t.elapsed() << endl;
    return 0;
}
