#ifndef SYSTEM_ICOMPARABLE_H
#define SYSTEM_ICOMPARABLE_H

#include "../../Defines.h"

#include "../../Utility.h"
#include "Int32.h"

namespace CppNet
{
	namespace System
	{
		template<typename T = System::Object>
		interface IComparable
		{
			virtual inline Int32 CompareTo(const T& obj) const = 0;
		};
	}
}

#endif