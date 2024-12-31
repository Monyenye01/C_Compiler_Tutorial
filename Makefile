# Compiler and flags
CC = cc
CFLAGS = -Wall -g

# Target executable
TARGET = scanner

# Source files
SOURCES = scanner.c Utils/scan.c Utils/data.c Utils/expr.c tree.c interp.c
HEADERS = Utils/defs.h Utils/data.h
OBJECTS = $(SOURCES:.c=.o)

# Default target
all: $(TARGET)

# Linking target executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Compiling source files to object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(TARGET) $(OBJECTS)
