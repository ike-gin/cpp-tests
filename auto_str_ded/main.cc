#include <string>

const std::string &get_ref();
const std::string &gte_ref_2();

const char *get_global_str() { return "Hello World"; }

int main() { std::string s = get_global_str(); }
