#makefile
#code compiler to use for compilation
CC=g++
#flags to use for compilation
CFLAGS = -g -Wall -Wpedantic
main: main.o student.o date.o address.o
	$(CC) $(CFLAGS) date.o address.o student.o main.o -o run
student.o: student.h student.cpp date.o address.o
	$(CC) $(CFLAGS) -c student.cpp
date.o: date.h date.cpp
	$(CC) $(CFLAGS) -c date.cpp
address.o: address.h address.cpp
	$(CC) $(CFLAGS) -c address.cpp
main.o: main.cpp student.h date.h address.h
	$(CC) $(CFLAGS) -c main.cpp
memtest: main
	valgrind --leak-check=yes ./run
clean:
	rm -f *.o
	rm -f run
	rm -f *.txt
run: main
	./run
