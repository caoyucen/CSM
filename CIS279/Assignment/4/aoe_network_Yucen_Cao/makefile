SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)
TARGET := aoe_network_runner
CXX_FLAGS := -std=c++11 

all: $(OBJS)
	g++ $(CXX_FLAGS) -O3 $(OBJS) -o $(TARGET)

%.o: %.cpp
	g++ $(CXX_FLAGS) -O3 -c $< -o $@

clean:
	rm -rf $(OBJS) $(TARGET)

zip:
	zip aoe_network_Yucen_Cao.zip *.cpp *.h *.hpp makefile README.md test_cases.txt output.pdf

