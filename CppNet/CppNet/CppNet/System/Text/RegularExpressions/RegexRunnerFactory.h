#ifndef CPPNET_KMC_SYSTEM_TEXT_REGULAREXPRESSIONS_REGEXRUNNERFACTORY_H
#define CPPNET_KMC_SYSTEM_TEXT_REGULAREXPRESSIONS_REGEXRUNNERFACTORY_H

#include "../../Object.h"

namespace CppNet
{
	namespace System
	{
		namespace Text
		{
			namespace RegularExpressions
			{
				class RegexRunnerFactory : public Object
				{
				protected:
					virtual RegexRunner CreateInstance() const = 0;
				};
			}
		}
	}
}

#endif