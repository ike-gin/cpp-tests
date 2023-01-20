#include <cstdio>
#include <unordered_map>
#include <vector>

struct S {
  S() { puts("S()"); }
  ~S() { puts("~S()"); }
  S(const S &) noexcept { puts("S(const S&)"); }
  S(S &&) noexcept { puts("S&&"); }
  S &operator=(const S &) noexcept {
    puts("operator=(S&)");
    return *this;
  }
  S &operator=(const S &&) noexcept {
    puts("operator=(S&&)");
    return *this;
  }
};

struct SHasher {
  std::size_t operator()(const S &k) const { return 5; }
};

bool operator==(const S, const S) { return true; }

int main() {
  std::vector<S> vec;
  vec.reserve(10);

  vec.emplace_back(S{});
  puts("first");

  vec.emplace_back(S{});
  puts("second");

  S s;
  S s2 = s;
  S s3(s2);

  s2 = s3;

  std::unordered_map<S, S, SHasher> map;
  map[s] = s3;

  puts("done");
  return 0;
}