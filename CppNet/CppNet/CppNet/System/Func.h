#ifndef SYSTEM_FUNC_H
#define SYSTEM_FUNC_H

#include "../../Defines.h"

#include <functional>

namespace CppNet
{
	namespace System
	{
		template <typename TResult, typename... Args>
		using Func = std::function<TResult(Args...)>;
	}
}

#endif