#include <iostream>

using namespace std;

struct S {
  S() { cout << "constructor was called" << endl; }
  int data;
};

int main() {
  S s;

  s.data = 5;

  cout << s.data << endl;
  return 0;
}
