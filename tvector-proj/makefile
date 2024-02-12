# Compiler and flags
CXX=g++
CXXFLAGS=-std=c++11

# Target executable name
TARGET=proj1.x

# Source files
SOURCES=tvector-driver.cpp

# Object files
OBJECTS=$(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# To generate object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: all clean
