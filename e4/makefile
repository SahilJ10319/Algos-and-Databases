e4: LinkedList.o main.o
		g++ -o e4 LinkedList.o main.o  							# indent must be a tab

LinkedList: LinkedList.h LinkedList.cpp
		g++ -c LinkedList.cpp LinkedList.h                       		# indent must be a tab

main: main.cpp
		g++ -c main.cpp											#indent must be a tab

clean:
		rm -f e4 LinkedList.o main.o    								# indent must be a tab

# same compiler options as for the course makefile
CPPFLAGS = -std=c++11