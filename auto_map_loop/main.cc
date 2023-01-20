#include <map>
#include <string>

const std::map<std::string, std::string> &get_data() { return {{"",""}}; }

int main() {
	for([[maybe_unused]] const auto &[key, value] : get_data())
	{

	}
}
