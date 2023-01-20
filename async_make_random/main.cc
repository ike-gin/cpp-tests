#include <iostream>
#include <set>
#include <algorithm>
#include <random>
#include <future>

std::set<int> make_sorted_random(const size_t num_elements) {

	std::set<int> retval;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, num_elements-1);

	std::generate_n(
		std::inserter(retval, retval.end()),
		num_elements,
		[&]() { return dis(gen); }
	);

	return retval;
}

int main(void) {

	auto f1 = std::async(/*std::launch::deferred,*/ make_sorted_random, 1000000);
	auto f2 = std::async(/*std::launch::deferred,*/ make_sorted_random, 1000000);

	std::cout << f1.get().size() << ' ' << f2.get().size() <<  std::endl;

	return 0;
}
