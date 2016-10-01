#ifndef SYSTEM_CHAR_H
#define SYSTEM_CHAR_H

#include "Object.h"
#include "Int32.h"
#include "UInt32.h"
#include "Byte.h"

#include "IComparable.h"
#include "IConvertible.h"
#include "IEquatable.h"

#include <string>
#include <array>

namespace System
{
	class Char : public virtual Object, public IComparable<Object>, public IComparable<Char>/*, public IConvertible*/, public IEquatable<Char>																  
	{
	public:
		Char() = default;
		Char(Int32 unicode);
		Char(std::array<char, 6> utf8chars);
		Char(std::array<char, 5> utf8chars);
		Char(std::array<char, 4> utf8chars);
		Char(std::array<char, 3> utf8chars);
		Char(std::array<char, 2> utf8chars);
		Char(char data);
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
		inline operator Int32();
		operator String();

		inline Char operator=(Char&& c);
		inline Char operator=(const Char& c);

		inline Boolean operator==(const Object& obj) override;
		inline Boolean operator!=(const Object& obj) override;

		inline Boolean operator>(const Char& c);
		inline Boolean operator<(const Char& c);
		inline Boolean operator>=(const Char& c);
		inline Boolean operator<=(const Char& c);

		inline Boolean operator>(char32_t c);
		inline Boolean operator<(char32_t c);
		inline Boolean operator>=(char32_t c);
		inline Boolean operator<=(char32_t c);

	private:
		Int32 dat;

	public:
		inline Int32 CompareTo(const Char& obj) override;
		inline Int32 CompareTo(const Object& obj) override;

	public:
		
	};
}

#include "Char.inl"

#endif