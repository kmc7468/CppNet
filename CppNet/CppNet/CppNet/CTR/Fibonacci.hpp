#ifndef CPPNET_CTR_FIBONACCI_H
#define CPPNET_CTR_FIBONACCI_H

#include "../System/UInt64.h"

namespace CppNet::CTR
{
	template<System::UInt64 n>
	struct Fibonacci final
	{
		enum { Value = Fibonacci<n - 1>::Value + Fibonacci<n - 2>::Value };
	};

	template<>
	struct Fibonacci<0> final
	{
		enum { Value = 1 };
	};

	template<>
	struct Fibonacci<1> final
	{
		enum { Value = 1 };
	};
}

#endif