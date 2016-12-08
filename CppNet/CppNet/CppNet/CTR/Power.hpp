#ifndef CPPNET_CTR_POWER_HPP
#define CPPNET_CTR_POWER_HPP

#include <utility>

#include "../System/UInt64.h"

namespace CppNet::CTR
{
	template<CppNet::System::UInt64 root, CppNet::System::UInt64 exp>
	struct Power final
	{
		enum : CppNet::System::UInt64 { Value = root * Power<root, exp - 1>::Value };
	};

	template<CppNet::System::UInt64 root>
	struct Power<root, 64> final
	{
		enum : CppNet::System::UInt64 { Value = std::numeric_limits<CppNet::System::UInt64>::max() };
	};

	template<CppNet::System::UInt64 root>
	struct Power<root, 0> final
	{
		enum : CppNet::System::UInt64 { Value = 1 };
	};
}

#endif