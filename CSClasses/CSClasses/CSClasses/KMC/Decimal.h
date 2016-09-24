#ifndef CSCLASSES_KMC_DECIMAL_H
#define CSCLASSES_KMC_DECIMAL_H

#include "../../SystemTypes.h"
#include <vector>
using namespace System;

namespace CSClasses
{
	namespace KMC
	{
		class Decimal final
		{
		public:
			Decimal() = default;
			Decimal(const String& str);
			Decimal(Int64 integer);
			Decimal(Double real);
			Decimal(Int64 integer, const String& real);
			Decimal(Decimal&& d);
			Decimal(const Decimal& d);
			~Decimal() = default;
		};
	}
}

#endif