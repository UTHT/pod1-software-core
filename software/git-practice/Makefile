TARGET = git_practice
BUILD_DIRS=build
$(shell mkdir -p $(BUILD_DIRS))

INC=-Iinclude

all: ${TARGET}
git_practice: src/main.cpp
	g++ $(INC) -o build/git_practice src/main.cpp
clean:
	rm -f ${TARGET}
