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
		std::unique_ptr<Threading::WaitHandle> AsyncWaitHandle() const;
		Object AsyncState() const;
		Boolean CompletedSynchronously() const;
	};
}

#endif