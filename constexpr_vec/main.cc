#include <vector>

constexpr int use_vector()
{
	std::vector<int> vec;
	return 5;
}

int main() {
	constexpr auto value = use_vector();
}
