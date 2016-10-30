#include "RegexRunner.h"

#include "Match.h"
#include "Regex.h"

#include "../../TimeSpan.h"

namespace CppNet
{
	namespace System
	{
		namespace Text
		{
			namespace RegularExpressions
			{
				Match RegexRunner::Scan(const Regex& regex, String text, Int32 textbeg, Int32 textend, Int32 textstart, Int32 prevlen, Boolean quick)
				{
					return Scan(regex, text, textbeg, textend, textstart, prevlen, quick, TimeSpan(std::numeric_limits<Int64>::max() - 1));
					// FIXME: Timeout - Timespan.FromMilliseconds(Int32.MaxValue - 1)
				}
			}
		}
	}
}