#ifndef SYSTEM_IDISPOSABLE_H
#define SYSTEM_IDISPOSABLE_H

#include "../../Defines.h"

#include "../../Utility.h"

namespace CppNet
{
	namespace System
	{
		interface IDisposable
		{
			virtual void Dispose() = 0;
		};
	}
}

#endif