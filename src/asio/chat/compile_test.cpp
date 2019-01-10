#include <boost/asio.hpp>

using boost::asio::ip::tcp;

void print()
{
}

template <class T, class ...Args>
void print(T head, Args... rest)
{
	print(rest...);
}

class compile_test
{
private:
    /* data */
public:
    compile_test(boost::asio::io_context&);
    ~compile_test();
};

compile_test::compile_test(boost::asio::io_context&)
{
}

compile_test::~compile_test()
{
}
