#-----------------------------------
# Lola Blue
# Makefile for sorting-algs program
# ----------------------------------
CPPFLAGS = -Wall -Wextra -std=c++11

all: sorts
sorts: main.o selection.o bubble.o insertion.o merge.o quick.o
	g++ -o sorts main.o selection.o bubble.o insertion.o merge.o quick.o
main.o: selection.h bubble.h
	g++ $(CPPFLAGS) -c main.cpp
selection.o: selection.h
	g++ $(CPPFLAGS) -c selection.cpp
bubble.o: bubble.h
	g++ $(CPPFLAGS) -c bubble.cpp
insertion.o: insertion.h
	g++ $(CPPFLAGS) -c insertion.cpp
merge.o: merge.h
	g++ $(CPPFLAGS) -c merge.cpp
quick.o: quick.h
	g++ $(CPPFLAGS) -c quick.cpp
clean:
	rm -f *.o sorts