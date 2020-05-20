#include <array>
#include <ostream>

template <std::size_t N>
struct constr : std::array<char, N> {
	private:
		template <std::size_t i = 0>
		constexpr void _init(const char (&str)[N]) {
			if constexpr (i < N) {
				this->at(i) = str[i];
				_init<i + 1>(str);
			}
		}

		template <std::size_t A, std::size_t B, std::size_t i = 0>
		static constexpr void _concat(const char* a, const char* b, constr<A + B - 1>& result) {
			if constexpr (i < A - 1) {
				result[i] = a[i];
				_concat<A, B, i + 1>(a, b, result);
			}
			else if constexpr (i < A + B - 1){
				result[i] = b[i - A + 1];
				_concat<A, B, i + 1>(a, b, result);
			}
		}

	public:
		constexpr constr() {}

		constexpr constr(const char (&str)[N]) {
			_init(str);
		}

		constexpr const char* raw() const {
			return this->data();
		}

		constexpr std::size_t size() const {
			return N;
		}

		template <std::size_t M>
		constexpr constr<N + M - 1> operator+(const constr<M>& other) const {
			constr<N + M - 1> result;
			_concat<N, M, 0>(raw(), other.raw(), result);
			return result;
		}

		friend std::ostream& operator<<(std::ostream& os, const constr<N>& str) {
			os << str.raw();
			return os;
		}
};
