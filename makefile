# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11

# Targets
TARGET = low_price
TEST_TARGET = Test

# Source files
SRC = low_price.cpp price_checker.cpp
TEST_SRC = Test.cpp price_checker.cpp

# Object files
OBJ = $(SRC:.cpp=.o)
TEST_OBJ = $(TEST_SRC:.cpp=.o)

# Default target: compile the main program
all: $(TARGET)

# Compile the main program
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Compile the unit test
test: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJ)

# Rule to create .o files from .cpp
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean the build
clean:
	rm -f $(OBJ) $(TEST_OBJ) $(TARGET) $(TEST_TARGET)
