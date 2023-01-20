#include <iostream>
#include <variant>

struct ThingA {
  void thisMethod() { std::cout << "ThingA" << std::endl; }
  int i = 5;
};

struct ThingB {
  void thatMethod() { std::cout << "ThingB" << std::endl; }
  char c = 'e';
};

struct ThingPrinter {
  void operator()(const ThingA &thing) { std::cout << thing.i << std::endl; }
  void operator()(const ThingB &thing) { std::cout << thing.c << std::endl; }
};

int main(void) {
  std::variant<ThingA, ThingB> thing = ThingB();

  std::visit(ThingPrinter{}, thing);

  ThingB *b = std::get_if<ThingB>(&thing);
  if (b) {
    b->c = 'z';
  }

  std::visit(ThingPrinter{}, thing);

  return 0;
}
