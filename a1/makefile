a1: Sequence.o test.o
		g++ -o a1 Sequence.o test.o                    # index must be a tab

Sequence: Sequence.h Sequence.cpp
		g++ -c Sequence.cpp Sequence.h                          # index must be a tab

test: test.cpp
		g++ -c test.cpp                                         # index must be a tab

clean:
		rm -f a1 Sequence.o test.o                         # index must be a tab

# same compiler options as for the course makefile
# CPPFLAGS = -std=c++14 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g                     