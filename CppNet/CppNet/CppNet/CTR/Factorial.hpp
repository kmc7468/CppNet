#ifndef CPPNET_CTR_FACTORIAL_HPP
#define CPPNET_CTR_FACTORIAL_HPP

#include "../System/UInt64.h"

namespace CppNet::CTR
{
	template<System::UInt64 n>
	struct Factorial final
	{
		enum { Value = n * Factorial<n - 1>::Value };
	};

	template<>
	struct Factorial<0> final
	{
		enum { Value = 1 };
	};
}

#endif