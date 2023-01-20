// clang-tidy should suggest <cstdio>
#include <stdio.h>

// cppcheck should suggest static for do_thing()
struct Thing {
	void do_thing() {}
	int data[10];
};

int main(void) {
	// clang-tidy should suggest Thing t{};
	Thing t;
	t.do_thing();

	puts("Hello World!");

	return 0;
}
