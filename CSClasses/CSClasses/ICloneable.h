#ifndef SYSTEM_ICLONEABLE_H
#define SYSTEM_ICLONEABLE_H

#include "System.h"

namespace System
{
	interface ICloneable
	{
		virtual Object Clone() = 0;
	};
}

#endif
