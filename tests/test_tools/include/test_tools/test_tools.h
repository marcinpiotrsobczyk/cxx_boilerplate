#pragma once

#include <iostream>
#include <string>


namespace tests { namespace test_tools {

    void PrintHello(std::string str = "from test tools");
    int GetNumber();
    int ThreadedFunction();

} }
