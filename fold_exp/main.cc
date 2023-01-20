#include <iostream>

template <typename... T> auto avg(T... t) { return (t + ...) / sizeof...(t); }

int main(void) {
  std::cout << avg(1, 2, 5.0, 7.77) << std::endl;

  return 0;
}
