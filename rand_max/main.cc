#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

int main(int, char *argv[]) {

	cout << UINT_MAX << endl;
	cout << RAND_MAX << endl;

	srand(atoi(argv[1]));

	cout << rand() << '\n';

	return 0;
}
