#include "Char.h"

#include "Exception.h"

namespace System
{
	Char::Char(Int32 unicode)
	{
		dat = unicode;
	}

	Char::Char(char32_t data)
	{
		dat = data;
	}

	Char::Char(char16_t data)
	{
		dat = data;
	}

	Char::Char(std::array<char, 4> chars)
		: Char(chars.data(), 4)
	{ }

	Char::Char(std::array<char, 3> chars)
		: Char(chars.data(), 3)
	{ }

	Char::Char(std::array<char, 2> chars)
		: Char(chars.data(), 2)
	{ }

	Char::Char(char data)
	{
		dat = data;
	}

	Char::Char(const char* chars, Byte size)
	{
		if (size <= 0 || size > 4)
		{
			//FIXME OverflowException

			throw Exception("응 오버플로~");
		}

		if (size == 4)
		{

		}
		else if (size == 3)
		{

		}
		else if (size == 2)
		{

		}
		else if (size == 1)
		{

		}
	}

	Char::Char(std::string chars)
		: Char(chars.c_str(), (Byte)chars.length())
	{ }
}