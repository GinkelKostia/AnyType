#include <gtest/gtest.h>
#include "AnyType.h"


TEST(AnyTests, EmptyStore) {
	ISXAnyType::Any a{};

	EXPECT_THROW(a.Get<int>(), BadAnyAccessException);
	EXPECT_EQ(a.GetType(), ISXAnyType::ValueType::Empty);
}

TEST(AnyTests, BoolStore) {
	ISXAnyType::Any a(true);

	EXPECT_TRUE(a.Get<bool>());
	EXPECT_EQ(a.GetType(), ISXAnyType::ValueType::Bool);
}

TEST(AnyTests, CharStore) {
	ISXAnyType::Any a(static_cast<char>('A'));

	EXPECT_EQ(a.Get<char>(), 'A');
	EXPECT_EQ(a.GetType(), ISXAnyType::ValueType::Char);
}
TEST(AnyTests, SignedCharStore) {
	ISXAnyType::Any a(static_cast<signed char>('A'));

	EXPECT_EQ(a.Get<signed char>(), 'A');
	EXPECT_EQ(a.GetType(), ISXAnyType::ValueType::SignedChar);
}
TEST(AnyTests, UnsignedCharStore) {
	ISXAnyType::Any a(static_cast<unsigned char>('A'));

	EXPECT_EQ(a.Get<unsigned char>(), 'A');
	EXPECT_EQ(a.GetType(), ISXAnyType::ValueType::UnsignedChar);
}

TEST(AnyTests, ShortStore) {
	ISXAnyType::Any a(static_cast<short>(10));

	EXPECT_EQ(a.Get<short>(), 10);
	EXPECT_EQ(a.GetType(), ISXAnyType::ValueType::Short);
}
TEST(AnyTests, UnsignedShortStore) {
	ISXAnyType::Any a(static_cast<unsigned short>(10));

	EXPECT_EQ(a.Get<unsigned short>(), 10);
	EXPECT_EQ(a.GetType(), ISXAnyType::ValueType::UnsignedShort);
}

TEST(AnyTests, IntStore) {
	ISXAnyType::Any a(10);

	EXPECT_EQ(a.Get<int>(), 10);
	EXPECT_EQ(a.GetType(), ISXAnyType::ValueType::Int);
}
TEST(AnyTests, UnsignedIntStore) {
	ISXAnyType::Any a(10u);

	EXPECT_EQ(a.Get<unsigned int>(), 10u);
	EXPECT_EQ(a.GetType(), ISXAnyType::ValueType::UnsignedInt);
}

TEST(AnyTests, LongStore) {
	ISXAnyType::Any a(10l);

	EXPECT_EQ(a.Get<long>(), 10l);
	EXPECT_EQ(a.GetType(), ISXAnyType::ValueType::Long);
}
TEST(AnyTests, UnsignedLongStore) {
	ISXAnyType::Any a(10ul);

	EXPECT_EQ(a.Get<unsigned long>(), 10ul);
	EXPECT_EQ(a.GetType(), ISXAnyType::ValueType::UnsignedLong);
}

TEST(AnyTests, LongLongStore) {
	ISXAnyType::Any a(10LL);

	EXPECT_EQ(a.Get<long long>(), 10);
	EXPECT_EQ(a.GetType(), ISXAnyType::ValueType::LongLong);
}
TEST(AnyTests, UnsignedLongLongStore) {
	ISXAnyType::Any a(10ULL);

	EXPECT_EQ(a.Get<unsigned long long>(), 10ULL);
	EXPECT_EQ(a.GetType(), ISXAnyType::ValueType::UnsignedLongLong);
}

TEST(AnyTests, DoubleStore) {
	ISXAnyType::Any a(5.5);

	EXPECT_EQ(a.Get<double>(), 5.5);
	EXPECT_EQ(a.GetType(), ISXAnyType::ValueType::Double);
}
TEST(AnyTests, LongDoubleStore) {
	ISXAnyType::Any a(5.5L);

	EXPECT_EQ(a.Get<long double>(), 5.5L);
	EXPECT_EQ(a.GetType(), ISXAnyType::ValueType::LongDouble);
}
TEST(AnyTests, FloatStore) {
	ISXAnyType::Any a(5.5f);

	EXPECT_EQ(a.Get<float>(), 5.5f);
	EXPECT_EQ(a.GetType(), ISXAnyType::ValueType::Float);
}

TEST(AnyTests, Char8TStore) {
	ISXAnyType::Any a(static_cast<char8_t>('A'));

	EXPECT_EQ(a.Get<char8_t>(), 'A');
	EXPECT_EQ(a.GetType(), ISXAnyType::ValueType::Char8_t);
}
TEST(AnyTests, Char16TStore) {
	ISXAnyType::Any a(static_cast<char16_t>('A'));

	EXPECT_EQ(a.Get<char16_t>(), 'A');
	EXPECT_EQ(a.GetType(), ISXAnyType::ValueType::Char16_t);
}
TEST(AnyTests, Char32TStore) {
	ISXAnyType::Any a(static_cast<char32_t>('A'));

	EXPECT_EQ(a.Get<char32_t>(), 'A');
	EXPECT_EQ(a.GetType(), ISXAnyType::ValueType::Char32_t);
}
TEST(AnyTests, WCharTStore) {
	ISXAnyType::Any a(static_cast<wchar_t>('A'));

	EXPECT_EQ(a.Get<wchar_t>(), 'A');
	EXPECT_EQ(a.GetType(), ISXAnyType::ValueType::WChar_t);
}


TEST(AnyTests, WrongTypeThrows) {
	ISXAnyType::Any a(10);

	EXPECT_THROW(a.Get<double>(), BadAnyAccessException);
}

TEST(AnyTests, CopyConstructor) {
	ISXAnyType::Any a(42);
	ISXAnyType::Any b(a);

	EXPECT_EQ(b.Get<int>(), 42);
}

TEST(AnyTests, MoveConstructor) {
	ISXAnyType::Any a(77);
	ISXAnyType::Any b(std::move(a));

	EXPECT_EQ(b.Get<int>(), 77);
	EXPECT_EQ(a.GetType(), ISXAnyType::ValueType::Empty);
}

TEST(AnyTests, AssignmentOperator) {
	ISXAnyType::Any a(5);
	ISXAnyType::Any b(10);

	b = a;

	EXPECT_EQ(b.Get<int>(), 5);
}

TEST(AnyTests, MoveAssignmentOperator) {
	ISXAnyType::Any a(123);
	ISXAnyType::Any b(456);

	b = std::move(a);

	EXPECT_EQ(b.Get<int>(), 123);
	EXPECT_EQ(a.GetType(), ISXAnyType::ValueType::Empty);
}

TEST(AnyTests, Clear) {
	ISXAnyType::Any a(100);

	a.Clear();

	EXPECT_EQ(a.GetType(), ISXAnyType::ValueType::Empty);
}


