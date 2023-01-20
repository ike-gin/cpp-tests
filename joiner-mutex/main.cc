#include <future>
#include <iostream>
#include <mutex>

int main() {
  using namespace std;

  mutex m;

  async(launch::async,
        [&m] {
          lock_guard{m};
          cout << "hello";
        }),
      async(launch::async, [&m] {
        lock_guard{m};
        cout << "world";
      });

  cout << "\nvery next task (always after helloworld or worldhello)" << endl;
}