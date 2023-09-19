#include <test_tools/test_tools.h>

#include <chrono>
#include <thread>


namespace tests { namespace test_tools {

    void PrintHello(std::string str /* = "from test tools" */)
    {
        std::cout << "hello " << str << std::endl;
    }

    int GetNumber()
    {
        return 15;
    }
    int ThreadedFunction()
    {
        using namespace std::chrono_literals;
        auto lambda = [] () {
            std::this_thread::sleep_for(60000ms);
            return 16;
        };
        int value = lambda();
        return value;
    }

} }
