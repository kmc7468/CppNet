#include "Char.h"

#include "Exception.h"

#include "BitConverter.h"

#include <string>
#include <algorithm>
using namespace std;

namespace System
{
	const Char Char::MaxValue = Char(std::numeric_limits<Int32>::max());
	const Char Char::MinValue = Char(std::numeric_limits<Int32>::min());

	Char::Char(Int32 unicode)
	{
		dat = unicode;
	}

	Char::Char(std::array<char, 6> utf8chars)
		: Char(utf8chars.data(), 6)
	{ }

	Char::Char(std::array<char, 5> utf8chars)
		: Char(utf8chars.data(), 5)
	{ }

	Char::Char(std::array<char, 4> utf8chars)
		: Char(utf8chars.data(), 4)
	{ }

	Char::Char(std::array<char, 3> utf8chars)
		: Char(utf8chars.data(), 3)
	{ }

	Char::Char(std::array<char, 2> utf8chars)
		: Char(utf8chars.data(), 2)
	{ }

	Char::Char(char data)
	{
		dat = data;
	}

	Char::Char(const char* utf8chars, Byte size, Byte index)
	{
		if (size <= 0 || size > 4)
		{
			//FIXME OverflowException

			throw Exception("응 오버플로~");
		}

		if (size == 6)
		{
			std::array<Byte, 6> arr;
			arr[0] = utf8chars[index + 0];
			arr[1] = utf8chars[index + 1];
			arr[2] = utf8chars[index + 2];
			arr[3] = utf8chars[index + 3];
			arr[4] = utf8chars[index + 4];
			arr[5] = utf8chars[index + 5];
			String bin = BitConverter::BytesToBinString<6>(arr);
			if (bin.length() != 48)
			{
				size_t more = 48 - bin.length();

				for (size_t i = 0; i < more; i++)
					bin = '0' + bin;
			}

			String one = bin.substr(0, 8);
			String two = bin.substr(8, 8);
			String three = bin.substr(16, 8);
			String four = bin.substr(24, 8);
			String five = bin.substr(32, 8);
			String six = bin.substr(35, 8);

			String undo = one.substr(7) + two.substr(2) + three.substr(2) + four.substr(2) + five.substr(2) + six.substr(2);

			var a = BitConverter::BinStringToBytes<4>(undo);

			dat = BitConverter::ToUInt32(a);
		}
		else if (size == 5)
		{
			std::array<Byte, 5> arr;
			arr[0] = utf8chars[index + 0];
			arr[1] = utf8chars[index + 1];
			arr[2] = utf8chars[index + 2];
			arr[3] = utf8chars[index + 3];
			arr[4] = utf8chars[index + 4];
			String bin = BitConverter::BytesToBinString<5>(arr);
			if (bin.length() != 35)
			{
				size_t more = 35 - bin.length();

				for (size_t i = 0; i < more; i++)
					bin = '0' + bin;
			}

			String one = bin.substr(0, 8);
			String two = bin.substr(8, 8);
			String three = bin.substr(16, 8);
			String four = bin.substr(24, 8);
			String five = bin.substr(32, 8);

			String undo = one.substr(6) + two.substr(2) + three.substr(2) + four.substr(2) + five.substr(2);

			var a = BitConverter::BinStringToBytes<4>(undo);

			dat = BitConverter::ToUInt32(a);
		}
		else if (size == 4)
		{
			std::array<Byte, 4> arr;
			arr[0] = utf8chars[index + 0];
			arr[1] = utf8chars[index + 1];
			arr[2] = utf8chars[index + 2];
			arr[3] = utf8chars[index + 3];
			String bin = BitConverter::BytesToBinString<4>(arr);
			if (bin.length() != 32)
			{
				size_t more = 32 - bin.length();

				for (size_t i = 0; i < more; i++)
					bin = '0' + bin;
			}

			String one = bin.substr(0, 8);
			String two = bin.substr(8, 8);
			String three = bin.substr(16, 8);
			String four = bin.substr(24, 8);

			String undo = one.substr(5) + two.substr(2) + three.substr(2) + four.substr(2);

			var a = BitConverter::BinStringToBytes<4>(undo);

			dat = BitConverter::ToUInt32(a);
		}
		else if (size == 3)
		{
			std::array<Byte, 3> arr;
			arr[0] = utf8chars[index + 0];
			arr[1] = utf8chars[index + 1];
			arr[2] = utf8chars[index + 2];
			String bin = BitConverter::BytesToBinString<3>(arr);
			if (bin.length() != 24)
			{
				size_t more = 24 - bin.length();

				for (size_t i = 0; i < more; i++)
					bin = '0' + bin;
			}

			String one = bin.substr(0, 8);
			String two = bin.substr(8, 8);
			String three = bin.substr(16, 8);

			String undo = one.substr(4) + two.substr(2) + three.substr(2);

			var a = BitConverter::BinStringToBytes<4>(undo);

			dat = BitConverter::ToUInt32(a);
		}
		else if (size == 2)
		{
			std::array<Byte, 2> arr;
			arr[0] = utf8chars[index + 0];
			arr[1] = utf8chars[index + 1];
			String bin = BitConverter::BytesToBinString<2>(arr);
			if (bin.length() != 16)
			{
				size_t more = 16 - bin.length();

				for (size_t i = 0; i < more; i++)
					bin = '0' + bin;
			}

			String one = bin.substr(0, 8);
			String two = bin.substr(8, 8);

			String undo = one.substr(3) + two.substr(2);

			var a = BitConverter::BinStringToBytes<4>(undo);

			dat = BitConverter::ToUInt32(a);
		}
		else if (size == 1)
		{
			std::array<Byte, 1> arr;
			arr[0] = utf8chars[index + 0];
			String bin = BitConverter::BytesToBinString<1>(arr);
			if (bin.length() != 8)
			{
				size_t more = 8 - bin.length();

				for (size_t i = 0; i < more; i++)
					bin = '0' + bin;
			}

			String one = bin.substr(0, 8);

			String undo = one.substr(1);

			var a = BitConverter::BinStringToBytes<4>(undo);

			dat = BitConverter::ToUInt32(a);
		}
	}

	Char::Char(std::string utf8chars)
		: Char(utf8chars.c_str(), (Byte)utf8chars.length())
	{ }

	Char::Char(Char&& c)
	{
		dat = c.dat;
	}

	Char::Char(const Char& c)
	{
		dat = c.dat;
	}

	Char::operator Int32()
	{
		return dat;
	}

	Char::operator String()
	{
		String bin = BitConverter::BytesToBinString(BitConverter::GetBytes(dat));

		if (bin.length() <= 7) // 0~7비트
		{
			bin.insert(bin.begin(), 7 - bin.length(), '0');

			String a = '0' + bin;

			var arr = BitConverter::BinStringToBytes<1>(a);

			String str = "";
			str += arr[0];

			return str;
		}
		else if (bin.length() >= 8 && bin.length() <= 11) // 8~11비트
		{
			bin.insert(bin.begin(), 11 - bin.length(), '0');

			String one = "110" + bin.substr(0, 5);
			String two = "10" + bin.substr(5, 6);

			var arr = BitConverter::BinStringToBytes<2>(one + two);

			String str = "";
			str += arr[0];
			str += arr[1];

			return str;
		}
		else if (bin.length() >= 12 && bin.length() <= 16) // 12~16비트
		{
			bin.insert(bin.begin(), 16 - bin.length(), '0');

			String one = "1110" + bin.substr(0, 4);
			String two = "10" + bin.substr(4, 6);
			String three = "10" + bin.substr(10, 6);

			var arr = BitConverter::BinStringToBytes<3>(one + two + three);

			String str = "";
			str += arr[0];
			str += arr[1];
			str += arr[2];

			return str;
		}
		else if (bin.length() >= 17 && bin.length() <= 21) // 17~21비트
		{
			bin.insert(bin.begin(), 21 - bin.length(), '0');

			String one = "11110" + bin.substr(0, 3);
			String two = "10" + bin.substr(3, 6);
			String three = "10" + bin.substr(9, 6);
			String four = "10" + bin.substr(15, 6);

			var arr = BitConverter::BinStringToBytes<4>(one + two + three + four);

			String str = "";
			str += arr[0];
			str += arr[1];
			str += arr[2];
			str += arr[3];

			return str;
		}
		else if (bin.length() >= 22 && bin.length() <= 26) // 22~26비트
		{
			bin.insert(bin.begin(), 26 - bin.length(), '0');

			String one = "111110" + bin.substr(0, 2);
			String two = "10" + bin.substr(2, 6);
			String three = "10" + bin.substr(8, 6);
			String four = "10" + bin.substr(14, 6);
			String five = "10" + bin.substr(20, 6);

			var arr = BitConverter::BinStringToBytes<5>(one + two + three + four + five);

			String str = "";
			str += arr[0];
			str += arr[1];
			str += arr[2];
			str += arr[3];
			str += arr[4];

			return str;
		}
		else if (bin.length() >= 27 && bin.length() <= 31) // 27~31비트
		{
			bin.insert(bin.begin(), 31 - bin.length(), '0');

			String one = "1111110" + bin.substr(0, 1);
			String two = "10" + bin.substr(1, 6);
			String three = "10" + bin.substr(7, 6);
			String four = "10" + bin.substr(13, 6);
			String five = "10" + bin.substr(19, 6);
			String six = "10" + bin.substr(25, 6);

			var arr = BitConverter::BinStringToBytes<6>(one + two + three + four + five + six);

			String str = "";
			str += arr[0];
			str += arr[1];
			str += arr[2];
			str += arr[3];
			str += arr[4];
			str += arr[5];

			return str;
		}

		throw Exception("응 인자오류~");
		// FIXME Argmeunt 뭐시기
	}
}