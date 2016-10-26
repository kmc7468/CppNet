#ifndef SYSTEM_CHAR_H
#define SYSTEM_CHAR_H

#include "../../Defines.h"

#include "Object.h"
#include "Int32.h"
#include "UInt32.h"
#include "Byte.h"

#include "IComparable.h"
#include "IConvertible.h"
#include "IEquatable.h"

#include <string>
#include <array>

namespace CppNet
{
	namespace System
	{
		class Char : public Object, public IComparable<Object>, public IComparable<Char>/*, public IConvertible*/, public IEquatable<Char>
		{
		public:
			Char() = default;
			Char(char32_t unicode);
			Char(std::array<char, 6> utf8chars);
			Char(std::array<char, 5> utf8chars);
			Char(std::array<char, 4> utf8chars);
			Char(std::array<char, 3> utf8chars);
			Char(std::array<char, 2> utf8chars);
			Char(const char* utf8chars, Byte size, Byte index = 0);
			Char(std::string utf8chars);
			Char(Char&& c);
			Char(const Char& c);
			~Char() = default;

		public:
			static const Char MaxValue;
			static const Char MinValue;

		public:
			inline Boolean Equals(const Char& obj) const override;
			inline Boolean Equals(Object& obj) const;

		public:
			inline operator UInt32();
			operator String();

			inline Char& operator=(Char&& c);
			inline Char& operator=(const Char& c);

			inline Boolean operator==(const Object& obj) const override;
			inline Boolean operator!=(const Object& obj) const override;

			inline Boolean operator>(const Char& c) const;
			inline Boolean operator<(const Char& c) const;
			inline Boolean operator>=(const Char& c) const;
			inline Boolean operator<=(const Char& c) const;

			inline Boolean operator>(char32_t c) const;
			inline Boolean operator<(char32_t c) const;
			inline Boolean operator>=(char32_t c) const;
			inline Boolean operator<=(char32_t c) const;

			inline Char operator+(const Char& c) const;
			inline Char operator-(const Char& c) const;
			inline Char operator*(const Char& c) const;
			inline Char operator/(const Char& c) const;
			inline Char operator%(const Char& c) const;

			inline Char& operator+=(const Char& c);
			inline Char& operator-=(const Char& c);
			inline Char& operator*=(const Char& c);
			inline Char& operator/=(const Char& c);
			inline Char& operator%=(const Char& c);

		private:
			char32_t dat;

		public:
			inline Int32 CompareTo(const Char& obj) const override;
			inline Int32 CompareTo(const Object& obj) const override;

		public:

		};
	}
}

#include "Char.inl"

#endif