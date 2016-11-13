#ifndef CPPNET_ICOPY_H
#define CPPNET_ICOPY_H

#include "../Defines.h"

#include "../Utility.h"

namespace CppNet
{
	template<typename T, typename DeepResult = T, typename ShallowResult = T>
	interface ICopy
	{
		virtual DeepResult DeepCopy() const = 0;
		virtual ShallowResult ShallowCopy() const = 0;
	};
}

#endif