#include <cstdio>

int main() {
  auto l = [i = 0]() mutable {
    puts("hey\n");
    return ++i;
  };

  l();

  return l();
}
