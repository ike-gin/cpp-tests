CC = clang++

main: main.cc Makefile
	clang-format-6.0 -i main.cc
#	clang-tidy-6.0 -checks=* main.cc
#	cppcheck --enable=all main.cc
	$(CC) -o main main.cc -Wall -Wextra -Wpedantic -march=native -std=c++17 -DTEST3

