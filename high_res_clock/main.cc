// high_resolution_clock example
#include <chrono>
#include <ctime>
#include <iostream>
#include <ratio>

int main() {
  // time_point difference example
  {
    using namespace std::chrono;

    const high_resolution_clock::time_point t1 = high_resolution_clock::now();

    std::cout << "printing out 1000 stars...\n";
    for (int i = 0; i < 1000; ++i)
      std::cout << "*";
    std::cout << std::endl;

    const high_resolution_clock::time_point t2 = high_resolution_clock::now();

    const duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

    std::cout << "It took me " << time_span.count() << " seconds." << std::endl;
  }

  // time since epoch
  {
    std::chrono::time_point<std::chrono::system_clock> p1, p2, p3;

    p2 = std::chrono::system_clock::now();
    p3 = p2 - std::chrono::hours(24);

    std::time_t epoch_time = std::chrono::system_clock::to_time_t(p1);
    std::cout << "epoch: " << std::ctime(&epoch_time);
    std::time_t today_time = std::chrono::system_clock::to_time_t(p2);
    std::cout << "today: " << std::ctime(&today_time);

    std::cout << "hours since epoch: "
              << std::chrono::duration_cast<std::chrono::hours>(
                     p2.time_since_epoch())
                     .count()
              << '\n';
    std::cout << "yesterday, hours since epoch: "
              << std::chrono::duration_cast<std::chrono::hours>(
                     p3.time_since_epoch())
                     .count()
              << '\n';

    for (int i = 0; i < 25; i++) {
      const std::chrono::time_point<std::chrono::system_clock> now =
          std::chrono::system_clock::now();

      std::cout << std::chrono::duration_cast<std::chrono::microseconds>(
                       now.time_since_epoch())
                       .count()
                << std::endl;
    }
  }

  return 0;
}
