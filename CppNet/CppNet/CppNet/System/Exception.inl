#include "Exception.h"

namespace CppNet::System
{
	const char* Exception::what() const noexcept
	{
#ifndef CppNet_Unsafe
		return "";
#else
		return nullptr;
#endif
	}
}