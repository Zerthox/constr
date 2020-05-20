#include <iostream>
#include "../src/constr.hpp"

constexpr constr a{"abc"};
constexpr constr b{"def"};

int main() {
	static_assert(a.size() == 4, "Invalid constr size");
	static_assert(a.raw()[0] == 'a', "Invalid constr.raw character at position 0");
	static_assert(a.raw()[1] == 'b', "Invalid constr.raw character at position 1");
	static_assert(a.raw()[2] == 'c', "Invalid constr.raw character at position 2");
	static_assert(a.raw()[3] == '\0', "Invalid constr.raw character at position 3");
	static_assert(a[0] == 'a', "Invalid constr.operator[] result");
	static_assert((a + b).size() == 7, "Invalid constr.operator+ result size");
	static_assert((a + b)[0] == 'a', "Invalid constr.operator+ result character at position 0");
	static_assert((a + b)[1] == 'b', "Invalid constr.operator+ result character at position 1");
	static_assert((a + b)[2] == 'c', "Invalid constr.operator+ result character at position 2");
	static_assert((a + b)[3] == 'd', "Invalid constr.operator+ result character at position 3");
	static_assert((a + b)[4] == 'e', "Invalid constr.operator+ result character at position 4");
	static_assert((a + b)[5] == 'f', "Invalid constr.operator+ result character at position 5");
	static_assert((a + b)[6] == '\0', "Invalid constr.operator+ result character at position 6");
	std::cout << "All tests successful." << std::endl;
}
