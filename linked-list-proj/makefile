# Makefile for compiling test_list

# Compiler settings - Can change these according to your system setup
CXX = g++
CXXFLAGS = -std=c++11

# Target executable name
TARGET = test_list

# Source files
SOURCES = test_list.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# To remove generated files
clean:
	rm -f $(TARGET) $(OBJECTS)

# Dependency
$(OBJECTS): $(SOURCES)

