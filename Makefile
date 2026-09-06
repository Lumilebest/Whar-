COMPILE := g++
COMPILEFLAGS := -std=c++20 -Wall -Wextra -Iinclude
LIB := -lSDL3

SRC := $(wildcard src/*.cpp src/*/*.cpp)
OBJ := $(patsubst src/%.cpp, build/%.o, $(SRC))
BIN := build/monjeu

$(BIN): $(OBJ)
	$(COMPILE) $(OBJ) -o $@ $(LIB)

build/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(COMPILE) $(COMPILEFLAGS) -c $< -o $@

run: $(BIN)
	./$(BIN)

clean:
	rm -rf build

.PHONY: run clean