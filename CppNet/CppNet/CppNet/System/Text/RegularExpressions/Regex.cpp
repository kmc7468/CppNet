#include "Regex.h"

#include "../../Threading/Timeout.h"

namespace CppNet
{
	namespace System
	{
		namespace Text
		{
			namespace RegularExpressions
			{
				const TimeSpan Regex::MaximumMatchTimeout = TimeSpan(MaxValue<Int32>() - 1);
				const TimeSpan Regex::InfiniteMatchTimeout = Threading::Timeout::InfiniteTimeSpan;
			}
		}
	}
}