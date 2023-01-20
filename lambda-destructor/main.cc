#include <cstdio>

int main() {
  auto l = [i = [] {
    struct S {
      ~S() { puts("Destroyed!"); }
      int val = 5;
    };
    return S{};
  }()] { return i; };

  return l().val;
}