#ifndef SYSTEM_IDISPOSABLE_H
#define SYSTEM_IDISPOSABLE_H

#include "../Utility.h"

namespace System
{
	interface IDisposable
	{
		virtual void Dispose() = 0;
	};
}

#endif