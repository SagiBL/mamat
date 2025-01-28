# Compiler and flags
CC = gcc
CFLAGS = -g -Wall -std=c99

# Linker flags
LDFLAGS = -o

# Target executable
TARGET = program.exe

# Source files
SRCS = main.c student.c stack.c
OBJS = $(SRCS:.c=.o)

# Default rule
all: $(TARGET)

# Linking step
$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) $(TARGET)

# Compilation step
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -rf *.o *.exe
