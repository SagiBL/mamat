# Compiler and flags
CC = gcc
CFLAGS = -Wall -g -std=c99
CLINK=$(CC)

all: stack.exe student.exe

student.exe: main.o student.o student.h
	$(CLINK) main.o student.o -o student.exe
student.o: student.c

stack.exe: main.o stack.o stack.h
	$(CLINK) main.o stack.o -o stack.exe
stack.o: stack.c

main.o: main.c common.h student.h stack.h

clean:
rm -f *.o *.exe

