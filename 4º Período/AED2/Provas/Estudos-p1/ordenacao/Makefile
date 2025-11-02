CXX = g++
CXXFLAGS = -Wall -std=c++17
SRC = main.cpp ./algoritmos/bubble-sort.cpp ./algoritmos/selection-sort.cpp ./algoritmos/insertion-sort.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = programa

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp IAlgoritmo.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
