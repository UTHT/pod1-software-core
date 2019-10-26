TARGET = git_practice
BUILD_DIRS=build
CFLAGS=`pkg-config --cflags lcm`
LDFLAGS=`pkg-config --libs lcm`
$(shell mkdir -p $(BUILD_DIRS))
# INC=-Iinclude -I../lcm/lcm
INC=-Iinclude

all: ${TARGET}
git_practice: src/main.cpp
	g++ $(INC) $(CFLAGS) $(LDFLAGS) -o build/git_practice src/main.cpp
clean:
	rm -f ${TARGET}
