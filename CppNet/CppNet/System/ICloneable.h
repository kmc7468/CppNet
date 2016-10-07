#ifndef SYSTEM_ICLONEABLE_H
#define SYSTEM_ICLONEABLE_H

#include "../Defines.h"

#include "../Utility.h"

namespace System
{
	interface ICloneable
	{
		virtual inline Object Clone() = 0;
	};
}

#endif
