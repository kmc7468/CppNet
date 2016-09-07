#ifndef SYSTEM_CONSOLE_H
#define SYSTEM_CONSOLE_H

#include <iostream>

namespace System
{
	class Console final
	{
	public:
		void WriteLine(const char* string)
		{
			std::cout << string << std::endl;
		}

		void WriteLine(int integer)
		{
			std::cout << integer << std::endl;
		}

		void Write(const char* string)
		{
			std::cout << string;
		}

		void Write(int integer)
		{
			std::cout << integer << std::endl;
		}
	};
}

#endif