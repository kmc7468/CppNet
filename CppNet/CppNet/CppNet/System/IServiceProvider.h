#ifndef SYSTEM_ISERVICEPROVIDER_H
#define SYSTEM_ISERVICEPROVIDER_H

#include "../../Defines.h"

#include "../../Utility.h"

#include "Object.h"
#include "Type.h"

namespace CppNet
{
	namespace System
	{
		interface IServiceProvider
		{
			virtual Object GetService(const Type& serviceType) = 0;
		};
	}
}

#endif