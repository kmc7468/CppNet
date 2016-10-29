#include "RegexRunner.h"

namespace CppNet
{
	namespace System
	{
		namespace Text
		{
			namespace RegularExpressions
			{
				const Int32 RegexRunner::TimeoutCheckFrequency = 1000;
			
				Match RegexRunner::Scan(Regex regex, String text, Int32 textbeg, Int32 textend, Int32 textstart, Int32 prevlen, Boolean quick, TimeSpan timeout)
				{
					Int32 bump = 0, stoppos = 0;
					Boolean initted = false;

					// TODO

					// FIXME
					return Match();
				}
			}
		}
	}
}