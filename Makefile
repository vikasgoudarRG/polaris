# Compiler
CXX = g++

# Target
TARGET = engine

# Source files
SRC = ./src/main.cc

# Output directories
DEBUG_DIR = ./debug
RELEASE_DIR = ./release

# Flags
DEBUG_FLAGS = -g -O0 -Wall
RELEASE_FLAGS = -O3 -Wall

# Default target
all: debug

# Debug build
debug:
	mkdir -p $(DEBUG_DIR)
	$(CXX) $(SRC) $(DEBUG_FLAGS) -o $(DEBUG_DIR)/$(TARGET)_debug

# Release build
release:
	mkdir -p $(RELEASE_DIR)
	$(CXX) $(SRC) $(RELEASE_FLAGS) -o $(RELEASE_DIR)/$(TARGET)_release

# Clean
clean:
	rm -rf $(DEBUG_DIR) $(RELEASE_DIR)
