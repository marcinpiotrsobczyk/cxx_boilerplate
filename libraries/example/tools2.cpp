#include <example/tools2.hpp>

namespace example {

int NotFullyCovered2(int n) {
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

} // namespace example
