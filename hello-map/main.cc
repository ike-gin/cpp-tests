#include <iostream>
#include <unordered_map>

int main() {
  for (const auto &letter : std::unordered_map<int, char>{{0, 'H'},
                                                          {1, 'e'},
                                                          {2, 'l'},
                                                          {3, 'l'},
                                                          {4, 'o'},
                                                          {5, ','},
                                                          {6, ' '},
                                                          {7, 'W'},
                                                          {8, 'o'},
                                                          {9, 'r'},
                                                          {10, 'l'},
                                                          {11, 'd'},
                                                          {12, '!'}}) {
    std::cout << letter.second;
  }

  std::cout << std::endl;
}