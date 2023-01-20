#include <cstdio>

struct S {
	private:
		int i = 1234;

		template<typename Self>
		static decltype(auto) get_i_common(Self *self) {
			return (self->i);
		}

	public:
		decltype(auto) get_i() {
			return get_i_common(this);
		}
		decltype(auto) get_i() const {
			return get_i_common(this);
		}
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
