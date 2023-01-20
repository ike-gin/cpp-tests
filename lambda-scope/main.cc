#include <iostream>

using namespace std;

int main() {
  int var = 66;

  cout << "var: " << var << endl;

  auto f = [var = 123456]() { cout << "il: " << var << endl; };

  f();

  cout << "var: " << var << endl;

  cout << "life was a mistake" << endl;
}