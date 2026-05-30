#pragma once
#include <utility>
#include <exception>

class BadAnyAccessException : public std::exception {
public:
	const char* what() const noexcept override {
		return "Bad access to the value of Any";
	}
};

namespace ISXAnyType {
	enum class ValueType {
		Empty,

		Bool,

		Char,
		SignedChar,
		UnsignedChar,

		Short,
		UnsignedShort,

		Int,
		UnsignedInt,

		Long,
		UnsignedLong,

		LongLong,
		UnsignedLongLong,

		Float,
		Double,
		LongDouble,

		Char8_t,
		Char16_t,
		Char32_t,
		WChar_t
	};

	class Any {
	private:
		union Type {
			bool b;

			char ch;
			signed char s_ch;
			unsigned char u_ch;

			short sh;
			unsigned short u_sh;

			int i;
			unsigned u_i;

			long l;
			unsigned long u_l;

			long long ll;
			unsigned long long u_ll;

			float f;
			double d;
			long double ld;

			char8_t ch8;
			char16_t ch16;
			char32_t ch32;
			wchar_t wch;
		} data;
		ValueType type;

		template <typename T>
		ValueType GetEnumType() const {
			if constexpr (std::is_same_v<T, bool>) return ValueType::Bool;
			else if constexpr (std::is_same_v<T, char>) return ValueType::Char;
			else if constexpr (std::is_same_v<T, signed char>) return ValueType::SignedChar;
			else if constexpr (std::is_same_v<T, unsigned char>) return ValueType::UnsignedChar;
			else if constexpr (std::is_same_v<T, short>) return ValueType::Short;
			else if constexpr (std::is_same_v<T, unsigned short>) return ValueType::UnsignedShort;
			else if constexpr (std::is_same_v<T, int>) return ValueType::Int;
			else if constexpr (std::is_same_v<T, unsigned int>) return ValueType::UnsignedInt;
			else if constexpr (std::is_same_v<T, long>) return ValueType::Long;
			else if constexpr (std::is_same_v<T, unsigned long>) return ValueType::UnsignedLong;
			else if constexpr (std::is_same_v<T, long long>) return ValueType::LongLong;
			else if constexpr (std::is_same_v<T, unsigned long long>) return ValueType::UnsignedLongLong;
			else if constexpr (std::is_same_v<T, float>) return ValueType::Float;
			else if constexpr (std::is_same_v<T, double>) return ValueType::Double;
			else if constexpr (std::is_same_v<T, long double>) return ValueType::LongDouble;
			else if constexpr (std::is_same_v<T, char8_t>) return ValueType::Char8_t;
			else if constexpr (std::is_same_v<T, char16_t>) return ValueType::Char16_t;
			else if constexpr (std::is_same_v<T, char32_t>) return ValueType::Char32_t;
			else if constexpr (std::is_same_v<T, wchar_t>) return ValueType::WChar_t;

			else throw BadAnyAccessException();
		}

		template <typename T>
		T& GetUnion() {
			if constexpr (std::is_same_v<T, bool>) return data.b;
			else if constexpr (std::is_same_v<T, char>) return data.ch;
			else if constexpr (std::is_same_v<T, signed char>) return data.s_ch;
			else if constexpr (std::is_same_v<T, unsigned char>) return data.u_ch;
			else if constexpr (std::is_same_v<T, short>) return data.sh;
			else if constexpr (std::is_same_v<T, unsigned short>) return data.u_sh;
			else if constexpr (std::is_same_v<T, int>) return data.i;
			else if constexpr (std::is_same_v<T, unsigned int>) return data.u_i;
			else if constexpr (std::is_same_v<T, long>) return data.l;
			else if constexpr (std::is_same_v<T, unsigned long>) return data.u_l;
			else if constexpr (std::is_same_v<T, long long>) return data.ll;
			else if constexpr (std::is_same_v<T, unsigned long long>) return data.u_ll;
			else if constexpr (std::is_same_v<T, float>) return data.f;
			else if constexpr (std::is_same_v<T, double>) return data.d;
			else if constexpr (std::is_same_v<T, long double>) return data.ld;
			else if constexpr (std::is_same_v<T, char8_t>) return data.ch8;
			else if constexpr (std::is_same_v<T, char16_t>) return data.ch16;
			else if constexpr (std::is_same_v<T, char32_t>) return data.ch32;
			else if constexpr (std::is_same_v<T, wchar_t>) return data.wch;

			else throw BadAnyAccessException();
		}
		template <typename T>
		const T& GetUnion() const {
			if constexpr (std::is_same_v<T, bool>) return data.b;
			else if constexpr (std::is_same_v<T, char>) return data.ch;
			else if constexpr (std::is_same_v<T, signed char>) return data.s_ch;
			else if constexpr (std::is_same_v<T, unsigned char>) return data.u_ch;
			else if constexpr (std::is_same_v<T, short>) return data.sh;
			else if constexpr (std::is_same_v<T, unsigned short>) return data.u_sh;
			else if constexpr (std::is_same_v<T, int>) return data.i;
			else if constexpr (std::is_same_v<T, unsigned int>) return data.u_i;
			else if constexpr (std::is_same_v<T, long>) return data.l;
			else if constexpr (std::is_same_v<T, unsigned long>) return data.u_l;
			else if constexpr (std::is_same_v<T, long long>) return data.ll;
			else if constexpr (std::is_same_v<T, unsigned long long>) return data.u_ll;
			else if constexpr (std::is_same_v<T, float>) return data.f;
			else if constexpr (std::is_same_v<T, double>) return data.d;
			else if constexpr (std::is_same_v<T, long double>) return data.ld;
			else if constexpr (std::is_same_v<T, char8_t>) return data.ch8;
			else if constexpr (std::is_same_v<T, char16_t>) return data.ch16;
			else if constexpr (std::is_same_v<T, char32_t>) return data.ch32;
			else if constexpr (std::is_same_v<T, wchar_t>) return data.wch;

			else throw BadAnyAccessException();
		}
		template <typename T>
		void Set(T val) {
			type = GetEnumType<T>();
			GetUnion<T>() = val;
		}
	public:
		Any() : type(ValueType::Empty) {}

		template <typename T>
		Any(T val) {
			Set(val);
		}

		~Any() { Clear(); }
		void Clear() { type = ValueType::Empty; }

		Any(const Any& other) : data(other.data), type(other.type) {}
		Any(Any&& other) noexcept : data(other.data), type(other.type) { other.Clear(); }
		ValueType GetType() const { return type; }
		void Swap(Any& other) {
			std::swap(data, other.data);
			std::swap(type, other.type);
		}

		template <typename T>
		T Get() const {
			if (type != GetEnumType<T>()) throw BadAnyAccessException();
			return GetUnion<T>();
		}

		Any& operator=(const Any& other) {
			if (this != &other) {
				data = other.data;
				type = other.type;
			}

			return *this;
		}
		Any& operator=(Any&& other) noexcept {
			if (this != &other) {
				data = other.data;
				type = other.type;

				other.Clear();
			}

			return *this;
		}
		template <typename T>
		Any& operator=(T val) {
			Set(val);
			return *this;
		}
	};
}