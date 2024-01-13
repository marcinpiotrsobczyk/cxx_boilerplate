#include <boost/version.hpp>
#include <iomanip>
#include <iostream>

int main() {
  std::cout << "boost version: " << BOOST_VERSION / 100000 << "."
            << BOOST_VERSION / 100 % 1000 << "." << BOOST_VERSION % 100
            << std::endl;
#if defined __GNUC__ && !defined __clang__
  std::cout << "gcc version: " << __GNUC__ << std::endl;
#endif
#if defined __clang__
  std::cout << "clang version: " << __clang__ << std::endl;
#endif
  return 0;
}
