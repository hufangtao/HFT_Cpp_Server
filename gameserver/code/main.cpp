#include "ext_head.h"
#include "player.h"
#include "tcp_server.h"

struct Test
{
    typedef int foo;
};

template <typename T>
void f(typename T::foo)
{
    cout << "template 1" << endl;
}

template <typename T>
void f(T)
{
    cout << "template 2" << endl;
}

template<class T, class U>
struct is_same_m
{
    void operator()()
    {
        cout << "template 1" << endl;
    }
};

template<class T>
struct is_same_m<T, T>
{
    void operator()()
    {
        cout << "template 2" << endl;
    }
};

int main()
{
    is_same_m<int, int> a;
    a();
    is_same_m<int, float> b;
    b();
    return 0;
}

