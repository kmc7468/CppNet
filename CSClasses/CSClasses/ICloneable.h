#ifndef SYSTEM_ICLONEABLE_H
#define SYSTEM_ICLONEABLE_H

#include "Object.h"
#include "Utility.h"

namespace System
{
	interface ICloneable
	{
		ICloneable() = delete;
		ICloneable(ICloneable&& i) = delete;
		ICloneable(const ICloneable& i) = delete;
		virtual ~ICloneable() = default;

		virtual inline Object Clone();
	};
}

#endif
