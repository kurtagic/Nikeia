# Variables
CC = g++
CFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = delphi
SRC = main.cpp Stack.cpp Interpreter.cpp Parser.cpp
LIBS = -lm

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(SRC)
	@echo "=== COMPILING: ==="
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LIBS)
	@echo "usage: ./delphi file.nka"

# Clean target
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean
