#ifndef CPPNET_SYSTEM_THREADING_TIMEOUT_H
#define CPPNET_SYSTEM_THREADING_TIMEOUT_H

#include "../Object.h"
#include "../TimeSpan.h"
#include "../UInt32.h"

namespace CppNet
{
	namespace System
	{
		namespace Threading
		{
			class Timeout final : public Object
			{
			public:
				static const TimeSpan InfiniteTimeSpan;
				static const Int32 Infinite;

			private:
				static const UInt32 UnsignedInfinite;
			};
		}
	}
}

#endif