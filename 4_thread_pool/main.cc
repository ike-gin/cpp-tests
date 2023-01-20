#include <chrono>
#include <iostream>
#include <thread>

void thread_func() {
  int64_t data = 0;
  for (int i = 0; i < 1'000'000; ++i) {
    for (int j = 0; j < 5000; ++j) {
      data += data * j - i;
    }
  }
}

int main() {
  std::thread threads[] = {std::thread(thread_func), std::thread(thread_func),
                           std::thread(thread_func), std::thread(thread_func)};

  for (auto &th : threads) {
    std::this_thread::sleep_for(std::chrono::milliseconds(15));

    if (th.joinable()) {
      std::cout << "thread " << th.get_id() << " complete" << std::endl;

      th.join();
      th = std::thread(thread_func);
    }
  }

  for (auto &th : threads) {
    std::cout << "thread " << th.get_id() << " complete" << std::endl;
    th.join();
  }

  return 0;
}
