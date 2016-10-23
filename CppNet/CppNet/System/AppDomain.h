#ifndef SYSTEM_APPDOMAIN_H
#define SYSTEM_APPDOMAIN_H

#include "../Utility.h"

namespace System
{
	interface _AppDomain
	{
		virtual void GetTypeInfoCount(UInt32& pcTInfo) const;
	};

	class AppDomain
	{

	};
}

#endif