exerciseOne: Sequence.o CMPT2251.o
		g++ -o exerciseOne Sequence.o CMPT2251.o  # indent must be a tab

Sequence: Sequence.h Sequence.cpp
		g++ -c Sequence.cpp Sequence.h                       		# indent must be a tab

CMPT2251: CMPT2251.cpp
		g++ -c CMPT2251.cpp											#indent must be a tab

clean:
		rm -f exerciseOne Sequence.o CMPT2251.o    								# indent must be a tab

# same compiler options as for the course makefile
# CPPFLAGS = -std=c++14 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g