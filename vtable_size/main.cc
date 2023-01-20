#include <iostream>
using namespace std;

class c {
  int a;
  int b;

  virtual int f() { return 5; }
};

class c2 {
  int c;

  virtual int f() { return 4; }
};

int main() {

  c cl;
  c c2;

  cout << sizeof(cl) << endl;
  cout << sizeof(c2) << endl;

  return 0;
}
