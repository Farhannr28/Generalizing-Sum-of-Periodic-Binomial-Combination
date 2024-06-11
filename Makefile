# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra

# Source directory
SRC_DIR = src

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Object directory
OBJ_DIR = obj

# Object files
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Output directory
BIN_DIR = bin

# Executable name
EXEC = main

# Default rule
all: $(BIN_DIR)/$(EXEC)

# Rule to build executable
$(BIN_DIR)/$(EXEC): $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

# Rule to compile source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create object directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Create output directory if it doesn't exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

run: $(BIN_DIR)/$(EXEC)
	$(BIN_DIR)/$(EXEC)

# Clean rule
clean:
	rm -f $(OBJS) $(EXEC)
