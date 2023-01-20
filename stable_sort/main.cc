#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

int main(void) {
  vector<string> words;
  words.reserve(200000);

  ifstream file_en("american-english");
  copy(istream_iterator<string>(file_en), istream_iterator<string>(),
       back_inserter(words));

  ifstream file_br("british-english");
  copy(istream_iterator<string>(file_br), istream_iterator<string>(),
       back_inserter(words));

  // sort lexigraphically first since 2 dictionaries are loaded
  sort(words.begin(), words.end(),
       [](const auto &a, const auto &b) { return a < b; });

  // remove dupes
  auto itr = unique(words.begin(), words.end());
  words.resize(std::distance(words.begin(), itr));

  // sort stably by length of the string
  stable_sort(words.begin(), words.end(),
              [](const auto &a, const auto &b) { return a.size() < b.size(); });

  for (auto &i : words) {
    cout << i << endl;
  }

  return 0;
}
