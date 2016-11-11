#ifndef CPPNET_CTR_MOD_HPP
#define CPPNET_CTR_MOD_HPP

#include <algorithm>

#include "../System/Double.h"
#include "../System/Single.h"
#include "../System/Int32.h"

namespace CppNet::CTR
{
	template<typename T, T x, T y>
	struct Mod final
	{
		enum : T { Value = x % y };
	};
}

#endif