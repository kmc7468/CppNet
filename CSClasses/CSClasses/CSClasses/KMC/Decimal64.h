#ifndef CSCLASSES_KMC_DECIMAL64_H
#define CSCLASSES_KMC_DECIMAL64_H

#include "../../SystemTypes.h"
#include <vector>
using namespace System;

namespace CSClasses
{
	namespace KMC
	{
		class Decimal64 final
		{
		public:
			Decimal64() = default;
			Decimal64(const String& str);
			Decimal64(Int64 integer);
			Decimal64(Double real);
			Decimal64(Int64 integer, const String& real);
			Decimal64(Decimal64&& d);
			Decimal64(const Decimal64& d);
			~Decimal64() = default;

		private:
			Int64 integer;
			Int64 real;
		};
	}
}

#endif