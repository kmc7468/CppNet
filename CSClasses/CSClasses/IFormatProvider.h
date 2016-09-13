#ifndef SYSTEM_IFORMATPROVIDER_H
#define SYSTEM_IFORMATPROVIDER_H

#include "Object.h"
#include "Utility.h"

namespace System
{
	interface IFormatProvider
	{
		template<typename T>
		virtual inline Object GetFormat(const T& formatType) = 0;
	};
}

#endif