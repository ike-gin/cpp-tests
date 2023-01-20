#include <cstring>
#include <iostream>

using namespace std;

template <typename T> struct dbk {
  T *dbk_data;

  ~dbk() { cout << "destructor called" << endl; }

private:
  int some_private_data;
};

struct specific_type : public dbk<specific_type> {
  int a;
  int b;
  char c;
};

template <typename T> T *getDBK() {
  T *data = new T;

  return data;
}

template <typename T> void storeDBK(T *dbk) {
  const unsigned char *const bytes = (unsigned char*)dbk;

  cout << sizeof(*dbk) << endl;
  for (long unsigned int i = 0; i < sizeof(*dbk); ++i) {
    printf("%i\n", bytes[i]);
  }
}

int main() {
  specific_type *s = getDBK<specific_type>();

  s->a = 1;
  s->b = 5;
  s->c = 'e';

  storeDBK<specific_type>(s);

  return 0;
}
