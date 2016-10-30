#include "Timeout.h"

namespace CppNet
{
	namespace System
	{
		namespace Threading 
		{
			const TimeSpan Timeout::InfiniteTimeSpan = TimeSpan(0, 0, 0, 0, Timeout::Infinite);
			const Int32 Timeout::Infinite = -1;
			const UInt32 Timeout::UnsignedInfinite = -1;
		}
	}
}