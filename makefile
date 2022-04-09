# Copied from StackOverflow (with modifications): this makefile will compile
# all .cpp files in the src directory and dump all .o files to the obj directory.
# Then, it links everything in the obj directory. It doesn't compile headers,
# but maybe that's not an issue.
SRC_DIR := src
OBJ_DIR := obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
LDFLAGS := -lncurses
CPPFLAGS := -ggdb -g3 -O0
CXXFLAGS := 

app: $(OBJ_FILES)
	g++ $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

# Automatically generates a dependency graph
CXXFLAGS += -MMD
-include $(OBJ_FILES:.o=.d)

clean:
	rm -r app
	rm -r obj/*