#include "Console.h"

#include <iomanip>

namespace System
{
	void Console::Write(Boolean boolean)
	{
		std::cout << (boolean ? L"True" : L"False");
	}

	void Console::Write(Char character)
	{
		// FIXME 임시조치. 나중에 유니코드 문자가 나오게 수정바람.
		std::cout << character.Unicode();
	}

	void Console::Write(const String& string)
	{
		std::cout << string;
	}

	void Console::Write(const String& string, Int32 index, Int32 count)
	{
		std::cout.write(string.c_str() + index, count);
	}

	void Console::Write(Double doubled)
	{
		std::cout << std::setprecision(4) << doubled;
	}

	void Console::Write(Double doubled, Int32 real_size)
	{
		std::cout << std::setprecision(real_size) << doubled;
	}

	void Console::Write(Int16 integer)
	{
		std::cout << integer;
	}

	void Console::Write(Int32 integer)
	{
		std::cout << integer;
	}

	void Console::Write(Int64 integer)
	{
		std::cout << integer;
	}

	void Console::Write(UInt16 integer)
	{
		std::cout << integer;
	}

	void Console::Write(UInt32 integer)
	{
		std::cout << integer;
	}

	void Console::Write(UInt64 integer)
	{
		std::cout << integer;
	}

	void Console::Write(Single single)
	{
		std::cout << std::setprecision(4) << single;
	}

	void Console::Write(Single single, Int32 real_size)
	{
		std::cout << std::setprecision(real_size) << single;
	}

	void Console::WriteLine()
	{
		std::cout << std::endl;
	}

	void Console::WriteLine(Boolean boolean)
	{
		std::cout << (boolean ? L"True" : L"False") << std::endl;
	}

	void Console::WriteLine(Char character)
	{
		// FIXME 나중에 유니코드 문자가 나오도록
		std::cout << character.Unicode() << std::endl;
	}

	void Console::WriteLine(const String& str)
	{
		std::cout << str << std::endl;
	}

	void Console::WriteLine(const String& string, Int32 index, Int32 count)
	{
		std::cout.write(string.c_str() + index, count) << std::endl;
	}

	void Console::WriteLine(Double doubled)
	{
		std::cout << std::setprecision(4) << doubled << std::endl;
	}

	void Console::WriteLine(Double doubled, Int32 real_size)
	{

		std::cout << std::setprecision(real_size) << doubled << std::endl;
	}

	void Console::WriteLine(Int16 integer)
	{
		std::cout << integer << std::endl;
	}

	void Console::WriteLine(Int32 integer)
	{
		std::cout << integer << std::endl;
	}

	void Console::WriteLine(Int64 integer)
	{
		std::cout << integer << std::endl;
	}

	void Console::WriteLine(UInt16 integer)
	{
		std::cout << integer << std::endl;
	}

	void Console::WriteLine(UInt32 integer)
	{
		std::cout << integer << std::endl;
	}

	void Console::WriteLine(UInt64 integer)
	{
		std::cout << integer << std::endl;
	}

	void Console::WriteLine(Single single)
	{
		std::cout << std::setprecision(4) << single << std::endl;
	}

	void Console::WriteLine(Single single, Int32 real_size)
	{
		std::cout << std::setprecision(real_size) << single << std::endl;
	}

	String Console::ReadLine()
	{
		String str;
		std::getline(std::cin, str);
		return str;
	}
	
	Int32 Console::Read()
	{
		Int32 i = std::cin.get();

		return i;
	}
}