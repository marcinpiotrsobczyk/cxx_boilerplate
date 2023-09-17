#include <example/tools.h>


namespace example { namespace tools {

    void print_hello(std::string str /* = "world" */)
    {
        std::cout << "hello " << str << std::endl;
    }

} }
