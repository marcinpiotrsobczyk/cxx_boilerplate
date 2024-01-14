#include <example/tools.hpp>

namespace example {

void PrintHello(std::string str /* = "world" */) {
  std::cout << "hello " << str << std::endl;
}

int GetNumber() { return 13; }

int NotFullyCovered(int n) {
  if (n == 1) {
    return 1;
  } else if (n == 2) {
    return 4;
  } else if (n == 3) {
    return 9;
  } else {
    return n * n;
  }
}

long long int NaiveFibonacci(int n) {
  if (n < 3)
    return n;
  else
    return NaiveFibonacci(n - 2) + NaiveFibonacci(n - 1);
}

} // namespace example
