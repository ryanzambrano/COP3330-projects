# Compiler and compiler flags
CXX = g++
CXXFLAGS = -Wall -g

# Name of the final executable
EXEC = proj3.mine.x

# Object files needed for the executable
OBJS = proj3_driver.o bet.o

# First target: Default target executed when just "make" is typed
all: $(EXEC)

# Rule to link the program
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

# Rule to compile the driver code
proj3_driver.o: proj3_driver.cpp bet.h
	$(CXX) $(CXXFLAGS) -c proj3_driver.cpp

# Rule to compile the BET implementation
bet.o: bet.cpp bet.h
	$(CXX) $(CXXFLAGS) -c bet.cpp

# Phony target for cleaning up the directory
clean:
	rm -f $(OBJS) $(EXEC)

run: $(EXEC)
    ./$(EXEC)


# Phony target to prevent make from getting confused by any files named "all" or "clean"
.PHONY: all clean
