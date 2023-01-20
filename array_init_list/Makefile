CC = g++

main: main.cc Makefile
	clang-format -i main.cc
#	clang-tidy -checks=* main.cc
#	cppcheck --enable=all main.cc
	$(CC) -o main main.cc -Wall -Wextra -Wpedantic -march=native -std=c++17 -DTEST3

