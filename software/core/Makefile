TARGET = core
BUILD_DIRS=build
CFLAGS=`pkg-config --cflags lcm`
LDFLAGS=`pkg-config --libs lcm`
OPTIONS=-std=c++17 -lstdc++fs
$(shell mkdir -p $(BUILD_DIRS))
INC=-Iinclude

all: ${TARGET}
core: src/main.cpp
	g++ $(INC) $(CFLAGS) $(LDFLAGS) $(OPTIONS) -o build/main src/*
clean:
	rm -f ${TARGET}
