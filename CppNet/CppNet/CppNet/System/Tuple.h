#ifndef SYSTEM_TUPLE_H
#define SYSTEM_TUPLE_H

#include "../../Defines.h"

#include <tuple>

namespace CppNet
{
	namespace System
	{
		template<typename... Args>
		using Tuple = std::tuple<Args...>;
	}
}

#endif