# Compiler
CC := g++
# Compiler flags
CFLAGS := -Wall -Wextra -std=c++11

# Source files
SRCS := ClsString.cpp ClsValidate.cpp main.cpp ClsDate.cpp ClsClient.cpp ClsPerson.cpp ClsUtil.cpp
# Object files
OBJS := $(SRCS:.cpp=.o)
# Header files
HDRS := ClsString.hh ClsValidate.hh ClsDate.hh ClsClient.hh ClsPerson.hh ClsUtil.hh

# Output executable
TARGET := make

# Build rule for generating object files
%.o: %.cpp $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

# Build rule for the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)

