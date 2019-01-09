#include <boost/asio.hpp>

using boost::asio::ip::tcp;
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
