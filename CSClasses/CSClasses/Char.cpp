#include "Char.h"

#include "Exception.h"

#include "BitConverter.h"

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

	Char::Char(const char* chars, Byte size, Byte index)
	{
		if (size <= 0 || size > 4)
		{
			//FIXME OverflowException

			throw Exception("응 오버플로~");
		}

		if (size == 4)
		{
			std::array<Byte, 4> arr;
			arr[0] = chars[0];
			arr[1] = chars[1];
			arr[2] = chars[2];
			arr[3] = chars[3];
			String bin = BitConverter::BytesToBinString<4>(arr);
			if (bin.length() != 32)
			{
				int more = 32 - bin.length();

				for (int i = 0; i < more; i++)
					bin = '0' + bin;
			}


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