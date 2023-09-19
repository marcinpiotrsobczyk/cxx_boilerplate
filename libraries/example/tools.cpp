#include <example/tools.hpp>


namespace example {

    void PrintHello(std::string str /* = "world" */)
    {
        std::cout << "hello " << str << std::endl;
    }

    int GetNumber()
    {
        return 13;
    }

}
