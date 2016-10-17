#ifndef SYSTEM_THREADING_THREAD_H
#define SYSTEM_THREADING_THREAD_H

#include "../Object.h"
#include "../Runtime/InteropServices/_Thread.h"

namespace System
{
	namespace Threading
	{
		class Thread final : public Object, public Runtime::InteropServices::_Thread
		{

		};
	}
}

#endif