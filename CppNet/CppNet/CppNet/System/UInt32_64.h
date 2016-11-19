#ifndef CPPNET_SYSTEM_UINT32_64_H
#define CPPNET_SYSTEM_UINT32_64_H

#include "../../Defines.h"

#include <iostream>

namespace CppNet::System
{
#ifdef BIT_64
	using UInt32_64 = std::uint64_t;
#else
	using UInt32_64 = std::uint32_t;
#endif
}

#endif