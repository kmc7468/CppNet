#ifndef SYSTEM_CONSOLE_H
#define SYSTEM_CONSOLE_H

#include "System.h"
#include <iostream>

namespace System
{
	class Console final : public Object
	{
	public:
		Console() = default;
		Console(Console &&sNewConsole) = delete;
		Console(const Console &sNewConsole) = delete;
		~Console() = default;

	public:
		Console &operator=(Console &&sNewConsole) = delete;
		Console &operator=(const Console &sNewConsole) = delete;

	public:
		inline void Write(Boolean boolean)
		{
			std::wcout << boolean;
		}

		inline void Write(Char character) const
		{
			std::wcout << character;
		}

		inline void Write(String string) const
		{
			std::wcout << string;
		}

		inline void Write(String string, Int32 index, Int32 count)
		{
			std::wcout.write(string + index, count);
		}

		inline void Write(Double doubled) const
		{
			std::wcout << doubled;
		}

		inline void Write(Int32 integer) const
		{
			std::wcout << integer;
		}

		inline void Write(Int64 integer) const
		{
			std::wcout << integer;
		}

		inline void Write(Single single) const
		{
			std::wcout << single;
		}

		inline void Write(String string) const
		{
			std::wcout << string;
		}

		inline void Write(UInt32 integer) const
		{
			std::wcout << integer;
		}

		inline void Write(UInt64 integer) const
		{
			std::wcout << integer;
		}

		inline void WriteLine() const
		{
			std::wcout << std::endl;
		}

		inline void WriteLine(Boolean boolean) const
		{
			std::wcout << boolean << std::endl;
		}

		inline void WriteLine(Char character) const
		{
			std::wcout << character << std::endl;
		}

		inline void WriteLine(String string) const
		{
			std::wcout << string << std::endl;
		}

		inline void WriteLine(String string, Int32 index, Int32 count)
		{
			std::wcout.write(string + index, count) << std::endl;
		}

		inline void WriteLine(Double doubled) const
		{
			std::wcout << doubled << std::endl;
		}

		inline void WriteLine(Int32 integer) const
		{
			std::wcout << integer << std::endl;
		}

		inline void WriteLine(Int64 integer) const
		{
			std::wcout << integer << std::endl;
		}

		inline void WriteLine(Single single) const
		{
			std::wcout << single << std::endl;
		}

		inline void WriteLine(String string) const
		{
			std::wcout << string << std::endl;
		}

		inline void WriteLine(UInt32 integer) const
		{
			std::wcout << integer << std::endl;
		}

		inline void WriteLine(UInt64 integer) const
		{
			std::wcout << integer << std::endl;
		}

		inline void WriteLine(UInt32 integer) const
		{
			std::wcout << integer << std::endl;
		}

		inline void WriteLine(UInt64 integer) const
		{
			std::wcout << integer << std::endl;
		}
	};
}

#endif