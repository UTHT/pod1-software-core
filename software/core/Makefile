TARGET = core
BUILD_DIRS=build
CFLAGS=`pkg-config --cflags lcm`
LDFLAGS=`pkg-config --libs lcm`
$(shell mkdir -p $(BUILD_DIRS))
INC=-Iinclude

all: ${TARGET}
core: src/main.cpp
	g++ $(INC) $(CFLAGS) $(LDFLAGS) -o build/main src/main.cpp
clean:
	rm -f ${TARGET}
