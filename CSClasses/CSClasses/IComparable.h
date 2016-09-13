#ifndef SYSTEM_ICOMPARABLE_H
#define SYSTEM_ICOMPARABLE_H

#include "Utility.h"
#include "Int32.h"
#include "Object.h"

namespace System
{
	interface IComparable
	{
		IComparable() = delete;
		IComparable(IComparable&& i) = delete;
		IComparable(const IComparable& i) = delete;
		virtual ~IComparable() = default;

		virtual inline Int32 CompareTo(const Object& obj);
	};
}

#include "IComparable.inl"

#endif