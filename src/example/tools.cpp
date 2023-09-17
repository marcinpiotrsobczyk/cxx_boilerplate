#include <example/tools.h>


namespace example { namespace tools {

    void PrintHello(std::string str /* = "world" */)
    {
        std::cout << "hello " << str << std::endl;
    }

    int GetNumber()
    {
        return 13;
    }

} }
