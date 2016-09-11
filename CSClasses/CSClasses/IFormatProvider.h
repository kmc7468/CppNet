#ifndef SYSTEM_IFORMATPROVIDER_H
#define SYSTEM_IFORMATPROVIDER_H

#include "Object.h"
#include "Utility.h"

namespace System
{
	interface IFormatProvider : public Object
	{
		IFormatProvider() = delete;
		IFormatProvider(IFormatProvider&& i) = delete;
		IFormatProvider(const IFormatProvider& i) = delete;
		virtual ~IFormatProvider() = default;

		// TODO
	};
}

#endif