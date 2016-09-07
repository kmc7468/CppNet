#ifndef SYSTEM_CONSOLE_H
#define SYSTEM_CONSOLE_H

#include "System.h"
#include <iostream>

namespace System
{
	class Console final : public Object
	{
	public:
		inline void WriteLine(const char* string) const
		{
			std::cout << string << std::endl;
		}

		inline void WriteLine(int integer) const
		{
			std::cout << integer << std::endl;
		}

		inline void Write(const char* string) const
		{
			std::cout << string;
		}

		inline void Write(int integer) const
		{
			std::cout << integer << std::endl;
		}
	};
}

#endif