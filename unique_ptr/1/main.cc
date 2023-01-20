#include <iostream>
#include <memory>

using namespace std;

class C {
public:
  int data;
};

int main(void) {

  unique_ptr<C> c = make_unique<C>();
  c.get()->data = 56;

  unique_ptr<C[]> ca = make_unique<C[]>(5);
  ca.get()[0].data = 1234;

  cout << ca.get()[0].data << endl << c.get()->data << endl;

  return 0;
}
