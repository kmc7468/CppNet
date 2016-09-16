#ifndef SYSTEM_CHAR_H
#define SYSTEM_CHAR_H

#include "Object.h"
#include "Int32.h" 
#include "Byte.h"

#include "IComparable.h"
#include "IConvertible.h"
#include "IEquatable.h"

#include <string>
#include <array>

namespace System
{
	class Char : public Object/*, public IComparable<Object>, public IComparable<Char>, public IConvertible, public IEquatable<Char>*/
	{
	public:
		Char() = default;
		Char(Int32 unicode);
		Char(char32_t data);
		Char(char16_t data);
		Char(std::array<char, 4> chars);
		Char(std::array<char, 3> chars);
		Char(std::array<char, 2> chars);
		Char(char data);
		Char(const char* chars, Byte size);
		Char(std::string chars);
		virtual ~Char() = default;

	private:
		Int32 dat;

	public:
		inline Int32 Unicode() const;
		inline char32_t Data() const;
	};
}

#include "Char.inl"

#endif