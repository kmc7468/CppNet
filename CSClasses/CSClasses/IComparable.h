#ifndef SYSTEM_ICOMPARABLE_H
#define SYSTEM_ICOMPARABLE_H

#include "Utility.h"
#include "Int32.h"
#include "Object.h"

namespace System
{
	interface IComparable
	{
		virtual inline Int32 CompareTo(const Object& obj) = 0;
	};
	
	template<typename T>
	interface IComparable<T> 
	{
		virtual inline Int32 CompareTo(const T& obj) = 0;
	};
}

#endif