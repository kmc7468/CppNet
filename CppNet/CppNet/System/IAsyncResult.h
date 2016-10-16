#ifndef SYSTEM_IASYNCRESULT_H
#define SYSTEM_IASYNCRESULT_H

#include "../Defines.h"
#include "../Utility.h"
#include "Threading/WaitHandle.h"

#include "Boolean.h"
#include "Object.h"

namespace System
{
	interface IAsyncResult
	{
		Boolean IsCompleted() const;
		Threading::WaitHandle AsyncWaitHandle() const;
		Object AsyncState() const;
		Boolean CompletedSynchronously() const;
	};
}

#endif