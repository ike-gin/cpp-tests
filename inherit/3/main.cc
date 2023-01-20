#include <iostream>

using namespace std;

class A {
public:
  virtual void a_memb() { cout << "a memb" << endl; }
  virtual void b_memb() { cout << "b from a" << endl; }
  void c_memb() { cout << "c from a" << endl; };
};

class B : public A {
public:
  virtual void a_memb() { cout << "a() from b" << endl; }
  virtual void b_memb() { cout << "b memb" << endl; }
};

class C : public A {
public:
  virtual void a_memb() { cout << "a() from c" << endl; }
  virtual void b_memb() { cout << "b() from c" << endl; }
  virtual void c_memb() { cout << "c memb" << endl; }
};

int main(void) {

  A *a = new C;

  a->c_memb();

  return 0;
}
