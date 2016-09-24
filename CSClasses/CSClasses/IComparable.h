#ifndef SYSTEM_ICOMPARABLE_H
#define SYSTEM_ICOMPARABLE_H

#include "Utility.h"
#include "Int32.h"
#include "Object.h"

namespace System
{
	template<typename T = Object>
	interface IComparable : private virtual Object
	{
		virtual inline Int32 CompareTo(const T& obj) = 0;
	};
}

#endif