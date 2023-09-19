#pragma once

#include <iostream>
#include <string>

namespace example_header_only {

void PrintHello(std::string str = "from header") {
  std::cout << "hello " << str << std::endl;
}
int GetNumber() { return 14; }

} // namespace example_header_only
