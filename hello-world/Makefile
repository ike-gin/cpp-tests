main: main.cc Makefile
	clang-format-6.0 -i main.cc
	g++-8 main.cc -o main -g -Wall -Wextra -Wpedantic -std=c++17

preprocessor: main.cc Makefile
	clang-format-6.0 -i main.cc
	g++-8 main.cc -g -Wall -Wextra -Wpedantic -std=c++17 -E
