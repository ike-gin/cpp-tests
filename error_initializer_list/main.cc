#include <initializer_list>
#include <iostream>

auto f(int i, int j, int k) { return std::initializer_list<int>{i, j, k}; }

int main(int argc, const char *[]) {
  for (int i : f(1 + argc, 2 + argc, 3 + argc)) {
    std::cout << i << "," << std::flush;
  }

  std::cout << std::endl;
}