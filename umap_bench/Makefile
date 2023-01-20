CC = clang++

main: main.cc Makefile
	clang-format-6.0 -i main.cc
	clang-tidy-6.0 -checks=* main.cc
	cppcheck --enable=all main.cc
	$(CC) -o main main.cc -Wall -Wextra -Wpedantic -O3 -s -march=native -std=c++17 -DTEST3

test: main Makefile
	./main scripts/hello-world.bas

run1: main.cc Makefile
	$(CC) -o main main.cc -Wall -Wextra -Wpedantic -O3 -s -march=native -std=c++17 -DTEST1
	ls -l main
	./main
	./main
	./main
	./main
	./main
	./main

run2: main.cc Makefile
	$(CC) -o main main.cc -Wall -Wextra -Wpedantic -O3 -s -march=native -std=c++17 -DTEST2
	ls -l main
	./main
	./main
	./main
	./main
	./main
	./main

run3: main.cc Makefile
	$(CC) -o main main.cc -Wall -Wextra -Wpedantic -O3 -s -march=native -std=c++17 -DTEST3
	ls -l main
	./main
	./main
	./main
	./main
	./main
	./main
