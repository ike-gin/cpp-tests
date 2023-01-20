#include <iostream>

using namespace std;

class A {
public:
  virtual void a_memb() { cout << "a memb" << endl; }
  void b_memb() { cout << "b from a" << endl; }
  void c_memb() { cout << "c from a" << endl; };
};

class B : A {
public:
  virtual void a_memb() { cout << "a() from b" << endl; }
  virtual void b_memb() { cout << "b memb" << endl; }
};

class C : B {
public:
  virtual void a_memb() { cout << "a() from c" << endl; }
  virtual void b_memb() { cout << "b() from c" << endl; }
  virtual void c_memb() { cout << "c memb" << endl; }
};

int main(void) {

  A a;
  a.a_memb();
  a.b_memb();
  a.c_memb();

  B b;

  b.a_memb();
  b.b_memb();

  C c;

  c.a_memb();
  c.b_memb();
  c.c_memb();

  return 0;
}
