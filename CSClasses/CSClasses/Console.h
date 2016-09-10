
/*
	2016.09.07
	Created by kmc7468
*/

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
		static inline void Write(Boolean boolean);
		static inline void Write(Char character);
		static inline void Write(const String& string);
		static inline void Write(const String& string, Int32 index, Int32 count);
		static inline void Write(Double doubled);
		static inline void Write(Int16 integer);
		static inline void Write(Int32 integer);
		static inline void Write(Int64 integer);
		static inline void Write(UInt16 integer);
		static inline void Write(UInt32 integer);
		static inline void Write(UInt64 integer);
		static inline void Write(Single single);

		static inline void WriteLine();
		static inline void WriteLine(Boolean boolean);
		static inline void WriteLine(Char character);
		static inline void WriteLine(const String& string);
		static inline void WriteLine(const String& string, Int32 index, Int32 count);
		static inline void WriteLine(Double doubled);
		static inline void WriteLine(Int16 integer);
		static inline void WriteLine(Int32 integer);
		static inline void WriteLine(Int64 integer);
		static inline void WriteLine(UInt16 integer);
		static inline void WriteLine(UInt32 integer);
		static inline void WriteLine(UInt64 integer);

		static inline String ReadLine();

		// TODO Read
	};
}

#include "Console.inl"

#endif