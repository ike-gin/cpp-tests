#include <array>
#include <iostream>

// There is currently no way to do this without rolling your own make_array,
// there is a proposal for this N3824: make_array which has the following scope:
//
// It also includes a sample implementation, which is rather long so copying
// here is impractical but Konrad Rudolph has a simplified version here which is
// consistent with the sample implementation above:

template <typename... T>
constexpr auto make_array(T &&...values) -> std::array<
    typename std::decay<typename std::common_type<T...>::type>::type,
    sizeof...(T)> {
  return std::array<
      typename std::decay<typename std::common_type<T...>::type>::type,
      sizeof...(T)>{std::forward<T>(values)...};
}

// clang does not allow auto as parameter dec, g++ will warn but allow
#if 0
void test(auto ar) {
  std::cout << "\n\n" << ar[2] << "\n\n";

  for (const auto &i : ar) {
    std::cout << i << std::endl;
  }
}
#endif

template <std::size_t SIZE> void test(const std::array<int, SIZE> &ar) {
  std::cout << "\n\n" << ar[2] << "\n\n";

  for (const auto &i : ar) {
    std::cout << i << std::endl;
  }
}

int main() {

  // does not work
  // std::array<int> a{1, 2, 3, 4, 5};

  // works if you don't specify the type
  std::array a1{1, 2, 3, 4, 5};
  test(a1);

  // reference implementation -- N3824: make_array
  const auto a2 = make_array(1, 2, 3, 4, 5, 6, 7, 8);
  test(a2);
}