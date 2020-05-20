#include <array>
#include <ostream>

template <std::size_t N>
struct constr : std::array<char, N> {
	private:
		template <std::size_t i = 0>
		constexpr void _init(const char (&str)[N]) noexcept {
			if constexpr (i < N) {
				this->at(i) = str[i];
				_init<i + 1>(str);
			}
		}

		template <std::size_t A, std::size_t B, std::size_t i = 0>
		static constexpr bool _compare(const char* a, const char* b) noexcept {
			if constexpr (A != B) {
				return false;
			}
			else if constexpr (i < A) {
				return a[i] == b[i] && _compare<A, B, i + 1>(a, b);
			}
			else {
				return true;
			}
		}

		template <std::size_t A, std::size_t B, std::size_t i = 0>
		static constexpr void _concat(const char* a, const char* b, constr<A + B - 1>& result) noexcept {
			if constexpr (i < A - 1) {
				result[i] = a[i];
				_concat<A, B, i + 1>(a, b, result);
			}
			else if constexpr (i < A + B - 1) {
				result[i] = b[i - A + 1];
				_concat<A, B, i + 1>(a, b, result);
			}
		}

	public:
		constexpr constr() noexcept {}

		constexpr constr(const char (&str)[N]) noexcept {
			_init(str);
		}

		constexpr const char* raw() const noexcept {
			return this->data();
		}

		constexpr std::size_t size() const noexcept {
			return N;
		}

		template <std::size_t M>
		constexpr bool operator==(const constr<M>& other) const noexcept {
			return _compare<N, M>(raw(), other.raw());
		}

		template <std::size_t M>
		constexpr bool operator!=(const constr<M>& other) const noexcept {
			return !operator==<M>(other);
		}

		template <std::size_t M>
		constexpr constr<N + M - 1> operator+(const constr<M>& other) const noexcept {
			constr<N + M - 1> result;
			_concat<N, M>(raw(), other.raw(), result);
			return result;
		}

		friend std::ostream& operator<<(std::ostream& os, const constr<N>& str) noexcept {
			os << str.raw();
			return os;
		}
};
