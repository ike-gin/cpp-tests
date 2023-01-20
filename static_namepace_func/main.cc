#include "junk.h"
#include <iostream>

int main(void) {
  std::cout << junk::someFunc().a << std::endl;
  std::cout << junk::someStaticFunc().a << std::endl;

  return 0;
}
