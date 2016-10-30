#ifndef CPPNET_SYSTEM_TEXT_REGULAREXPRESSIONS_REGEX_H
#define CPPNET_SYSTEM_TEXT_REGULAREXPRESSIONS_REGEX_H

#include "../../../../Defines.h"

#include "../../Runtime/Serialization/ISerializable.h"

#include "RegexRunnerFactory.h"
#include "RegexOptions.h"

namespace CppNet
{
	namespace System
	{
		namespace Text
		{
			namespace RegularExpressions
			{
				class Regex/* : public Runtime::Serialization::ISerializable*/
				{
				protected:
					String pattern;
					RegexRunnerFactory* factory = nullptr;
					RegexOptions roptions = RegexOptions::None;

					TimeSpan internalMatchTimeout = 0;

				private:
					static const TimeSpan MaximumMatchTimeout;

				public:
					static const TimeSpan InfiniteMatchTimeout;
				};
			}
		}
	}
}

#endif