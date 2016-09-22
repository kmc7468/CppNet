#ifndef SYSTEM_IEQUATABLE_H
#define SYSTEM_IEQUATABLE_H

#include "Utility.h"

namespace System
{
	template<typename T>
	interface IEquatable : private Object
	{
		virtual inline Boolean Equals(const T& obj) const = 0;
	};
}

#endif