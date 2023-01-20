#include <cstdio>

struct S {
	private:
		int i = 1235;
	public:
		int &get_i() {
			return const_cast<int &>(static_cast<const S*>(this)->get_i()); }
		const int &get_i() const { return i; }
};

int main()
{
	S s;
	printf("%i\n", s.get_i());

	const S s2;
	printf("%i\n", s2.get_i());

	S s3;
	s3.get_i() = 777;
	printf("%i\n", s3.get_i());

	return 0;
}
