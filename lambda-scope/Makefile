CC = g++

main: main.cc Makefile
	clang-format -i main.cc
	$(CC) -o main main.cc -Wall -Wextra -Wpedantic -O3 -s -march=native -std=c++17