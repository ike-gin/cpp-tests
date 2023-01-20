#include <cstdio>

int main()
{
	const int i = 0;
	const_cast<int &>(i) = 42;

	printf("%i\n", i);

	return 0;
}
