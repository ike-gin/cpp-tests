main: main.o
	g++ main.o -o main

main.o: main.cc
	clang-tidy -checks=* main.cc
	cppcheck --enable=all main.cc
	g++ main.cc -c

clean:
	rm main.o
