#ifndef CPPNET_CTR_POWER_HPP
#define CPPNET_CTR_POWER_HPP

#include <utility>

#include "../System/UInt64.h"

namespace CppNet::CTR
{
	template<size_t root, size_t exp>
	struct Power final
	{
		enum : size_t { Value = root * Power<root, exp - 1>::Value };
	};

	template<size_t root>
	struct Power<root, 64> final
	{
		enum : size_t { Value = std::numeric_limits<CppNet::System::UInt64>::max() };
	};

	template<size_t root>
	struct Power<root, 0> final
	{
		enum : size_t { Value = 1 };
	};
}

#endif