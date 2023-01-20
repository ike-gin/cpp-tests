#include "main.h"
#include <iostream>

extern int another_source_var;

using namespace std;
int main() {

  cout << some_other_variable << endl;
  cout << another_source_var << endl;
  cout << some_other_func() << endl;

  return 0;
}
