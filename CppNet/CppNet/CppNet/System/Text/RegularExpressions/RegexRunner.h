#ifndef CPPNET_SYSTEM_TEXT_REGULAREXPRESSIONS_REGEXRUNNER_H
#define CPPNET_SYSTEM_TEXT_REGULAREXPRESSIONS_REGEXRUNNER_H

#include "../../Object.h"
#include "../../Int32.h"
#include "../../TimeSpan.h"

#include "Match.h"
#include "Regex.h"

namespace CppNet
{
	namespace System
	{
		namespace Text
		{
			namespace RegularExpressions
			{
				class Regex;

				class RegexRunner abstract : public Object
				{
				protected:
					Int32 runtextbeg;
					Int32 runtextend;
					Int32 runtextstart;

					String runtext;
					Int32 runtextpos;

					Int32* runtrack = nullptr;
					Int32 runtrackpos;

					Int32* runstack = nullptr;
					Int32 runstackpos;

					Int32* runcrawl = nullptr;
					Int32 runcrawlpos;

					Int32 runtrackcount;

					Match* runmatch = nullptr;
					Regex* runregex = nullptr;

				private:
					Int32 timeout;
					Boolean ignoreTimeout;
					Int32 timeoutOccursAt;

				private:
					static const Int32 TimeoutCheckFrequency;

				private:
					Int32 timeoutChecksToSkip;

				protected:
					inline Match Scan(const Regex& regex, String text, Int32 textbeg, Int32 textend, Int32 textstart, Int32 prevlen, Boolean quick);
					Match Scan(const Regex& regex, String text, Int32 textbeg, Int32 textend, Int32 textstart, Int32 prevlen, Boolean quick, TimeSpan timeout);
				};
			}
		}
	}
}

#include "RegexRunner.inl"

#endif