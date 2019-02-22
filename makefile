EXEC  = proj2
CC = g++
CFLAGS = -c -Wall -ggdb
CXXFLAGS = -ggdb -Wall


$(EXEC) :utility.o heap.o graph.o main.o
	 $(CC) -o $(EXEC) utility.o heap.o graph.o main.o

util.o :utility.h utility.cpp
	$(CC) $(CFLAGS) utility.cpp

heap.o :heap.h heap.cpp
	$(CC) $(CFLAGS) heap.cpp

graph.o :graph.h graph.cpp
	$(CC) $(CFLAGS) graph.cpp
main.o :main.cpp
	$(CC) $(CFLAGS) main.cpp

clean : 
	rm *.o

