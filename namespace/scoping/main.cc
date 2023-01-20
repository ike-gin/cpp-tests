#include <iostream>

int main() {
  if (true) {
    using namespace std;
    cout << "true is a fact" << endl;
  }

  std::cout << "back out in a sane scope" << std::endl;
}