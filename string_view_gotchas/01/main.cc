#include <iostream>
#include <string>
#include <string_view>

using namespace std::string_literals;

int main() {

  std::string sv = "test"s;
  std::cout << sv[0] << std::endl;

  return 0;
}