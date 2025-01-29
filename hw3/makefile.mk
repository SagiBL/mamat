# Compiler and flags
CC = gcc
CFLAGS = -Wall -g -std=c99
CLINK=$(CC)


prog.exe: main.o student.o stack.o
	$(CLINK) main.o student.o stack.o -o prog.exe

student.o: student.c student.h
stack.o: stack.c stack.h
main.o: main.c common.h student.h stack.h

clean:
rm -f *.o *.exe

