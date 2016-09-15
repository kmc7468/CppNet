#ifndef SYSTEM_STRING_H
#define SYSTEM_STRING_H

#include <string>

namespace System
{
	using String = std::basic_string<Char, std::char_traits<Char>, std::allocator<Char>>;
}

#endif