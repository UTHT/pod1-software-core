TARGET = example
BUILD_DIRS=build
CFLAGS=`pkg-config --cflags lcm`
LDFLAGS=`pkg-config --libs lcm`
$(shell mkdir -p $(BUILD_DIRS))
# INC=-Iinclude -I../lcm/lcm
INC=-Iinclude

all: ${TARGET}
example: src/send.cpp src/listen.cpp
	g++ $(INC) $(CFLAGS) $(LDFLAGS) -o build/send src/send.cpp
	g++ $(INC) $(CFLAGS) $(LDFLAGS) -o build/listen src/listen.cpp
clean:
	rm -f ${TARGET}
