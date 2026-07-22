CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20
TARGET = tcp_example

all: $(TARGET)

$(TARGET): main.cpp Protocol.hpp NetworkCoding.hpp
	$(CXX) $(CXXFLAGS) main.cpp -o $(TARGET)

clean:
	rm -f $(TARGET)
