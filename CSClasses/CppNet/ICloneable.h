#ifndef SYSTEM_ICLONEABLE_H
#define SYSTEM_ICLONEABLE_H

#include "Object.h"
#include "Utility.h"

namespace System
{
	interface ICloneable : private virtual Object
	{
		virtual inline Object Clone() = 0;
	};
}

#endif
