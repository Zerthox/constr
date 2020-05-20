#include <iostream>
#include "../src/constr.hpp"

constexpr constr a{"abc"};
constexpr constr b{"de"};
constexpr constr c{"xyz"};
constexpr constr d{"abc"};

int main() {
	static_assert(a.size() == 4, "Invalid constr size");
	static_assert(a.raw()[0] == 'a', "Invalid constr.raw character at position 0");
	static_assert(a.raw()[1] == 'b', "Invalid constr.raw character at position 1");
	static_assert(a.raw()[2] == 'c', "Invalid constr.raw character at position 2");
	static_assert(a.raw()[3] == '\0', "Invalid constr.raw character at position 3");
	static_assert(a[0] == 'a', "Invalid constr.operator[] result");
	static_assert((a + b).size() == 6, "Invalid constr.operator+ result size");
	static_assert((a + b)[0] == 'a', "Invalid constr.operator+ result character at position 0");
	static_assert((a + b)[1] == 'b', "Invalid constr.operator+ result character at position 1");
	static_assert((a + b)[2] == 'c', "Invalid constr.operator+ result character at position 2");
	static_assert((a + b)[3] == 'd', "Invalid constr.operator+ result character at position 3");
	static_assert((a + b)[4] == 'e', "Invalid constr.operator+ result character at position 4");
	static_assert((a + b)[5] == '\0', "Invalid constr.operator+ result character at position 6");
	static_assert(a == d, "Invalid constr.operator== result with same operands");
	static_assert(a != c, "Invalid constr.operator== result with different operands with same length");
	static_assert(a != b, "Invalid constr.operator== result with different operands with different length");
	std::cout << "All tests successful." << std::endl;
}
