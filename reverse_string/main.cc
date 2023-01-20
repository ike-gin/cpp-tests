#include <iostream>
#include <string>
#include <vector>

using namespace std;

// loops through half the string swaping characters inplace
string naive_inplace(string &str) {
  const int LEN = str.length();
  for (int a = 0, b = LEN - 1; b >= LEN / 2; ++a, --b) {
    int swaptemp = str[a];
    str[a] = str[b];
    str[b] = swaptemp;
  }

  return str;
}

// loops through the full string storing characters backward
string naive_copy(const string &str) {
  string result{str};
  return naive_inplace(result);
}

// our test strings
vector<string> get_test_strings() {
  return {
      {"even"},
      {"odd"},
      {""},
      {"a slightly longer string with spaces"},
  };
}

int main() {

  // naive (in place)
  {
    vector<string> strings{get_test_strings()};
    for (auto &str : strings) {
      cout << str << " --> " << naive_inplace(str) << endl;
    }
  }
  cout << endl;

  // naive (copy)
  {
    vector<string> strings{get_test_strings()};
    for (const auto &str : strings) {
      cout << str << " --> " << naive_copy(str) << endl;
    }
  }
  cout << endl;

  // std::reverse (in place)
  {
    vector<string> strings{get_test_strings()};
    for (auto &str : strings) {
      cout << str << " --> ";
      reverse(str.begin(), str.end());
      cout << str << endl;
    }
  }
  cout << endl;

  // string construction via reverse iterators (copy)
  {
    vector<string> strings{get_test_strings()};
    for (auto &str : strings) {
      string reversed(str.rbegin(), str.rend());
      cout << str << " --> " << reversed << endl;
    }
  }
  cout << endl;

  return 0;
}
