#include <ctime>
#include <iostream>

int main() {
  for (int i = 0; i < 25; ++i) {
    std::cout << time(NULL) << std::endl;
  }
}