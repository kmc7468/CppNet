#ifndef SYSTEM_RUNTIME_INTEROPSERVICES__THREAD_H
#define SYSTEM_RUNTIME_INTEROPSERVICES__THREAD_H

#include "../../../Utility.h"

#include "../../../SystemTypes.h"
#include "../../Guid.h"

namespace System
{
	namespace Runtime
	{
		namespace InteropServices
		{
			interface _Thread
			{
				void GetTypeInfoCount(UInt32& pcTInfo);

				void GetTypeInfo(UInt32 iTInfo, UInt32 lcid, const IntPtr& ppTInfo);

				void GetIDsOfNames(Guid& riid, const IntPtr& rgszNames, UInt32 cNames, UInt32 lcid, const IntPtr& rgDispId);

				void Invoke(UInt32 dispIdMember, Guid& riid, UInt32 lcid, Int16 wFlags, const IntPtr& pDispParams, const IntPtr& pVarResult, const IntPtr& pExcepInfo, const IntPtr& puArgErr);
			};
		}
	}
}

#endif