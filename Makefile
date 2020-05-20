FLAGS = -Wall -Wextra -std=c++17

all: test

.PHONY: test
test: test/test run clean

test/test: src/constr.hpp test/test.cpp
	$(CXX) test/test.cpp -o test/test $(FLAGS)

.PHONY: run
run: test/test
	./test/test

.PHONY: clean
clean:
ifeq ($(OS), Windows_NT)
	del test\test.exe
else
	rm test/test
endif
