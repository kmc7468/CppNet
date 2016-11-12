#ifndef CPPNET_SYSTEM_THREADING_ITHREADPOOLWORKITEM_HPP
#define CPPNET_SYSTEM_THREADING_ITHREADPOOLWORKITEM_HPP

#include "../../../Defines.h"
#include "../../../Utility.h"

#include "Tasks/Task.hpp"
#include "ThreadAbortException.hpp"

namespace CppNet::System::Threading
{
	namespace Tasks
	{
		class Task;
	}

	interface IThreadPoolWorkItem
	{
		friend class Tasks::Task;

	private:
		virtual void ExecuteWorkItem() = 0;
		virtual void MarkAborted(const ThreadAbortException& tae) = 0;
	};
}

#endif