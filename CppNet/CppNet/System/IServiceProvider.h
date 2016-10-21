#ifndef SYSTEM_ISERVICEPROVIDER_H
#define SYSTEM_ISERVICEPROVIDER_H

#include "../Utility.h"

namespace System
{
	interface IServiceProvider
	{
		virtual Object GetService(const Type& serviceType) = 0;
	};
}

#endif