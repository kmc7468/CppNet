#ifndef SYSTEM_IFORMATTABLE_H
#define SYSTEM_IFORMATTABLE_H

#include <memory>

#include "Utility.h"

#include "String.h"
#include "IFormatProvider.h"

namespace System
{
	interface IFormattable : private Object
	{
		virtual inline String ToString(String format, std::unique_ptr<IFormatProvider> formatProvider) = 0;
	};
}

#endif