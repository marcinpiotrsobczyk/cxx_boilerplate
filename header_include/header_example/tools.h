#include <iostream>
#include <string>


namespace header_example { namespace tools {

    void PrintHello(std::string str = "from header") {
        std::cout << "hello " << str << std::endl;
    }
    int GetNumber() {
        return 14;
    }

} }
