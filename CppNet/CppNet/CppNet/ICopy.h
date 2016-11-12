#ifndef CPPNET_ICOPY_H
#define CPPNET_ICOPY_H

#include "../Defines.h"

#include "../Utility.h"

namespace CppNet
{
	template<typename T>
	interface ICopy
	{
		virtual T DeepCopy() const = 0;
		virtual T ShallowCopy() const = 0;
	};
}

#endif