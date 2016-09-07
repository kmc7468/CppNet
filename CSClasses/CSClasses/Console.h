#ifndef SYSTEM_CONSOLE_H
#define SYSTEM_CONSOLE_H

#include <iostream>

namespace System
{
	class Console final
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

		inline void Write(const Char *string) const
		{
			std::wcout << string;
		}

		inline void Write(const Char *string, Int32 index, Int32 count)
		{
			std::wcout.write(string + index, count);
		}

		inline void Write(Double doubled) const
		{
			std::wcout << doubled;
		}

		inline void Write(Int32 integer) const
		{
			std::cout << integer;
		}

		inline void Write(Int64 integer) const
		{
			std::cout << integer;
		}

		inline void Write(UInt32 integer) const
		{
			std::cout << integer;
		}

		inline void Write(UInt64 integer) const
		{
			std::cout << integer;
		}

		inline void WriteLine() const
		{
			std::cout << std::endl;
		}

		inline void WriteLine(Boolean boolean) const
		{
			std::cout << std::endl;
		}

		inline void WriteLine(const char* string) const
		{
			std::cout << string << std::endl;
		}

		inline void WriteLine(int integer) const
		{
			std::cout << integer << std::endl;
		}
	};
}

#endif