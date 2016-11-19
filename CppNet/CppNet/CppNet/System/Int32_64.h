#ifndef CPPNET_SYSTEM_INT32_64_H
#define CPPNET_SYSTEM_INT32_64_H

#include "../../Defines.h"

#include <iostream>

namespace CppNet::System
{
#ifdef BIT_64
	using Int32_64 = std::int64_t;
#else
	using Int32_64 = std::int32_t;
#endif
}

#endif