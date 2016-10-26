#ifndef SYSTEM_KEYVALUEPAIR_H
#define SYSTEM_KEYVALUEPAIR_H

#include "../../Defines.h"

#include <tuple>

namespace CppNet
{
	namespace System
	{
		template<typename TKey, typename TValue>
		using KeyValuePair = std::pair<TKey, TValue>;
	}
}

#endif