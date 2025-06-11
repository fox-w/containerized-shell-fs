# Define compiler
CC = gcc

# Define flags
CFLAGS = -Wall -Wextra -pedantic -std=c99 -Iinclude -g

# Define sources and object files
SOURCES = src/shell.c src/tokenizer.c
OBJECTS = src/shell.o src/tokenizer.o

# Define target executable
TARGET = shell

# Default target
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

# Rule to compile shell.c into shell.o
src/shell.: src/shell.c
	$(CC) $(CFLAGS) -c src/shell.c -o src/shell.o

# Rule to compile tokenizer.c into tokenizer.o
src/tokenizer.o: src/tokenizer.c
	$(CC) $(CFLAGS) -c src/tokenizer.c -o src/tokenizer.o

# Define clean target
clean:
	rm -f $(TARGET) $(OBJECTS)
