CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude
LDFLAGS = -Llib -lGL -lGLU -lglut -lGLEW

SRCS = src/main.cpp src/drawing.cpp src/bezier.cpp
OBJS = $(SRCS:.cpp=.o)

TARGET = bezier_curve

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
