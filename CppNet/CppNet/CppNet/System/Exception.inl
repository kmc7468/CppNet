#include "Exception.h"

namespace CppNet::System
{
	const char* Exception::what() const
	{
#ifndef CppNet_Unsafe
		return "";
#else
		return nullptr;
#endif
	}
}