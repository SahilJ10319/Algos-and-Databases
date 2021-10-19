a2: Deque.o test.o
		g++ -o a2 Deque.o test.o                    # index must be a tab

Deque: Deque.h 
		g++ -c Sequence.h                          # index must be a tab

test: test.cpp
		g++ -c test.cpp                                         # index must be a tab

clean:
		rm -f a1 Deque.o test.o                         # index must be a tab

# same compiler options as for the course makefile
CPPFLAGS = -std=c++14 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g                     