#include <algorithm>
#include <chrono>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
using namespace std::chrono;

std::string gen_random_string(size_t length) {
  auto randchar = []() -> char {
    const char charset[] = "0123456789"
                           "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                           "abcdefghijklmnopqrstuvwxyz";
    const size_t max_index = (sizeof(charset) - 1);
    return charset[rand() % max_index];
  };
  std::string str(length, 0);
  std::generate_n(str.begin(), length, randchar);
  return str;
}

high_resolution_clock::time_point t1;
void start_timer() { t1 = high_resolution_clock::now(); }

void stop_timer(const char *const event) {
  high_resolution_clock::time_point t2 = high_resolution_clock::now();
  duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

  cout << event << " time: " << time_span.count() << endl;
}

int main() {
  const int MAP_SIZE = 500000;
  const int MAP_ACCESSES = 1000000;

  // test unordered_map vs map
  using test_type = map<int, string>;
  test_type m;

  vector<string> list_of_strings(MAP_SIZE);
  generate_n(list_of_strings.begin(), MAP_SIZE,
             []() { return gen_random_string(24); });

  start_timer();

  // generate a randomized map
  for (int i = 0; i < MAP_SIZE; ++i) {
    m[i] = list_of_strings[i];
  }

  stop_timer("gen");

  // generate a list of indicies to access in the map
  vector<int> accesses(MAP_ACCESSES);
  generate_n(accesses.begin(), MAP_ACCESSES,
             []() { return rand() % MAP_SIZE; });

  start_timer();

  // do some work that can't be optimized out (take the first char from each
  // access location and add it to the result string)
  string result;
  result.reserve(MAP_ACCESSES);

#ifdef TEST1
  for (int i = 0; i < MAP_ACCESSES; ++i) {
    result += m[accesses[i]][0];
  }
#endif

#ifdef TEST2
  for (const auto &a : accesses) {
    result += m[a][0];
  }
#endif

#ifdef TEST3
  for_each(accesses.begin(), accesses.end(),
           [&](const int &a) { result += m[a][0]; });
#endif

  stop_timer("acc");
  // cout << result << endl;

  return 0;
}
