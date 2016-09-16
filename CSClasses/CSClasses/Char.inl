#include "Char.h"

namespace System
{
	Int32 Char::Unicode() const
	{
		return dat;
	}

	char32_t Char::Data() const
	{
		return dat;
	}
}