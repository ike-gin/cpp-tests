#include <cstring>
#include <iostream>

using namespace std;

struct S {
  int a = 5;
  int b = 128;
  char c = 'e';
};

int main() {
  S *s = new S;

  {
    unsigned char *b = (unsigned char *)s;
    for (long unsigned int i = 0; i < sizeof(*s); ++i) {
      printf("%i\n", b[i]);
    }
  }

  delete s;
}
